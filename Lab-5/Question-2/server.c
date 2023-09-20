#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

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

  
    int choice, num1, num2, result;
    recv(new_socket, &choice, sizeof(choice), 0);
    recv(new_socket, &num1, sizeof(num1), 0);
    recv(new_socket, &num2, sizeof(num2), 0);

 
    switch (choice) {
        case 1:
            result = num1 + num2; 
            break;
        case 2:
            result = num1 - num2; 
            break;
        case 3:
            result = num1 * num2; 
            break;
        case 4:
            if (num2 != 0)
                result = num1 / num2;
            else
                result = -1; 
            break;
        default:
            result = -1; 
    }

    
    send(new_socket, &result, sizeof(result), 0);

    printf("Result sent to client: %d\n", result);
    close(new_socket);

    return 0;
}
