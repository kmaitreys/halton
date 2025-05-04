#include <stdio.h>
#include <gsl/gsl_qrng.h>

#define DIMENSIONS 2
#define NUM_POINTS 1000

void generate_halton_sequence(unsigned int dimensions, unsigned int num_points, FILE *output) {
    gsl_qrng *qrng = gsl_qrng_alloc(gsl_qrng_halton, dimensions);
    
    double *point = malloc(dimensions * sizeof(double));
    
    for (unsigned int i = 0; i < num_points; i++) {
        gsl_qrng_get(qrng, point);
        
        for (unsigned int j = 0; j < dimensions; j++) {
            fprintf(output, "%f ", point[j]);
        }
        fprintf(output, "\n");
    }
    
    gsl_qrng_free(qrng);
    free(point);
}

int main() {
    FILE *output = fopen("gsl_halton_output.txt", "w");
    if (output == NULL) {
        perror("Error opening output file");
        return 1;
    }

    generate_halton_sequence(DIMENSIONS, NUM_POINTS, output);

    fclose(output);
    return 0;
}


