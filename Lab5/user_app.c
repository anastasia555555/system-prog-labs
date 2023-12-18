#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/random_bits_device"
#define BUF_SIZE 4

int main() {
    int fd;
    unsigned int rand_bit;
    ssize_t bytes_read;

    fd = open(DEVICE_PATH, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    bytes_read = read(fd, &rand_bit, sizeof(rand_bit));
    if (bytes_read == -1) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Random bit read from the device: %u\n", rand_bit);

    close(fd);

    return EXIT_SUCCESS;
}
