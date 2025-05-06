

#include "minishell.h"


// char *get_path_env(char **envp) {
//     while (*envp) {
//         if (ft_strncmp(*envp, "PATH=", 5) == 0)
//             return *envp + 5;
//         envp++;
//     }
//     return NULL;
// }

// char **get_paths(char **envp) {
//     char *path_env = get_path_env(envp);
//     if (!path_env)
//         return NULL;
//     return ft_split(path_env, ':');
// }

char **get_paths(char **envp) {
    while (*envp) {
        if (ft_strncmp(*envp, "PATH=", 5) == 0)
            return ft_split(*envp + 5, ':');
        envp++;
    }
    return NULL;
}

char *find_command_path(char *cmd, char **envp) {
    char **paths = get_paths(envp);
    char *full_path;
    int i = 0;

    if (!paths)
        return NULL;
    while (paths[i]) {
        full_path = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(full_path, cmd);  
        if (access(full_path, X_OK) == 0)
            return full_path; 
        free(full_path);
        i++;
    }
    return NULL;
}


int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;

    char *prompt;
    char **args;
    char *cmd_path;
    pid_t pid;

    while (1)
    {
        prompt = readline("🍄minishell$ ");
        if (!prompt)
            break;
        if (ft_strlen(prompt) == 0)
        {
            free(prompt);
            continue;
        }
        if (ft_strncmp(prompt, "exit", 5) == 0)
        {
            free(prompt);
            break;
        }
        args = ft_split(prompt, ' ');
        free(prompt); 
        if (!args || !args[0])
            continue;
        cmd_path = find_command_path(args[0], envp);
        if (!cmd_path)
        {
            printf( "%s: command not found\n", args[0]);
            continue;
        }
        pid = fork();
        if (pid == 0)
        {
            execve(cmd_path, args, envp);
            perror("execve failed");
            exit(1);
        }
        else if (pid > 0)
        {
            waitpid(pid, NULL, 0);
        }
        else
        {
            perror("fork failed");
        }
    }
    return 0;
}