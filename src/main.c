#include <stdio.h>
#include <stdlib.h>

#include "forrestParsing.h"
#include "forrestPrinting.h"

void usage(char *progName){
  printf("Usage: %s <distance> <duration> [step]\n"
      "  - distance examples : 3km, 200m, 3km500, 1500m, 400 (default unit: meter)\n"
      "  - duration examples : 1h27m4, 27m, 2h3, 1h45s, 30 (default unit: second)\n"
      "  - step : step used to print the times targets. Same format as distance\n"
      "           default: 200m if the distance is <= 5km and 1km otherwise\n", progName);
}

int main(int argc, char **argv){
  int meters;
  int seconds;
  int stepMeters;

  if (argc < 3 || argc > 4){
    fprintf(stderr, "Error: bad number of argument\n\n");
    usage(argv[0]);
    return EXIT_FAILURE;
  }

  if (parseDistance(argv[1], &meters) != 0){
    fprintf(stderr, "Error: problem occured while parsing the distance\n\n");
    usage(argv[0]);
    return EXIT_FAILURE;
  }

  if (parseDuration(argv[2], &seconds) != 0){
    fprintf(stderr, "Error: problem occured while parsing the duration\n\n");
    usage(argv[0]);
    return EXIT_FAILURE;
  }

  if (meters > 5000)
    stepMeters = 1000;
  else
    stepMeters = 200; /* half an athletics track */

  if (argc == 4){
    if (parseDistance(argv[3], &stepMeters) != 0){
      fprintf(stderr, "Error: problem occured while parsing the step\n\n");
      usage(argv[0]);
      return EXIT_FAILURE;
    }
  }

  printSpeed(meters,seconds);
  printTimeTargets(meters,seconds, stepMeters);

  return EXIT_SUCCESS;
}
