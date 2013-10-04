/*

FSB Bench test

(c) Thanat0s.trollprod.org / 2013

Licence WTF

*/

// ************ LIB ***************
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <zlib.h>
#include <errno.h>

// ************ Variables **********
//char file[256]=

// ************ Const **************

#define True 1;
#define LENGTH 0xFFFF

// ************ Code **************
int gzcat(const char * file_name) {
    gzFile file;
    file = gzopen (file_name, "r");
    if (file == NULL) {
        fprintf (stderr, "Error gzopen of '%s' failed: %s.\n", file_name,
                 strerror (errno));
            exit (EXIT_FAILURE);
    }
    while (1) {
        int err;                    
        int bytes_read;
        unsigned char buffer[LENGTH];
        bytes_read = gzread (file, buffer, LENGTH - 1);
        buffer[bytes_read] = '\0';
        printf ("%s", buffer);
        if (bytes_read < LENGTH - 1) {
            if (gzeof (file)) {
                break;
            }
            else {
                const char * error_string;
                error_string = gzerror (file, & err);
                if (err) {
                    fprintf (stderr, "Error: %s.\n", error_string);
                    exit (EXIT_FAILURE);
                }
            }
        }
    }
    gzclose (file);
	return(0);	
}

int main(void){
	int cat;
	cat = gzcat;
	(cat("test.gz"));
	return(0);	
	}

