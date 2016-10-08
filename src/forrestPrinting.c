#include <stdio.h>

void computeBeautifulDistance(int meters, char *out){
  if (meters >= 1000)
    sprintf(out, "%.06g km", meters * 1.0 / 1000);
  else
    sprintf(out, "%d m", meters);
}

void computeBeautifulDuration(int seconds, char *out){
  int hours;
  int minutes;

  hours = seconds / 3600;
  seconds = seconds % 3600;
  minutes = seconds / 60;
  seconds = seconds % 60;
  sprintf(out, "%d:%02d:%02d", hours, minutes, seconds);
}

void printSpeed(int meters, int seconds){
  printf("speed: %.02f km/h\n\n", 3.6 * meters / seconds );
}

void printTimeTargets(int meters, int seconds, int stepMeters){
  char duration[10]; /* max length : 111:22:33 (+ '\0') */
  char distance[11]; /* max length : 444.150 km (+ '\0') */
  int tmpDist = 0;
  while (tmpDist < meters - stepMeters) {
    tmpDist += stepMeters;
    computeBeautifulDistance(tmpDist, distance);
    computeBeautifulDuration(tmpDist * seconds / meters, duration);
    printf("%10s : %s\n", distance, duration);
  }
  computeBeautifulDistance(meters, distance);
  computeBeautifulDuration(seconds, duration);
  printf("%10s : %s\n", distance, duration);
}

