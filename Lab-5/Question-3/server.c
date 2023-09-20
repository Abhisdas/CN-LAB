#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>

#define PORT 8080


bool isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[1024];

  
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;


    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding error");
        exit(1);
    }

  
    if (listen(server_fd, 10) == 0) {
        printf("Server listening on port %d...\n", PORT);
    } else {
        perror("Listening error");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    new_socket = accept(server_fd, (struct sockaddr *)&new_addr, &addr_size); 
    
    char client_string[1024];
    recv(new_socket, client_string, sizeof(client_string), 0);

   
    bool is_palindrome = isPalindrome(client_string);


    send(new_socket, &is_palindrome, sizeof(is_palindrome), 0);

    if (is_palindrome) {
        printf("The received string is a palindrome.\n");
    } else {
        printf("The received string is not a palindrome.\n");
    }

    close(new_socket);

    return 0;
}
