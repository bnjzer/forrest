#include <ctype.h>

int parseDistance(char *distArg, int *meters){
  int currentTotal; /* buffer that keeps the read digits from the arg */

  *meters = 0;
  currentTotal = 0;

  while (*distArg != '\0'){
    if (!isspace(*distArg)){ /* just in case that for a reason " or ' are used for the arguments */
      if (isdigit(*distArg))
        currentTotal = currentTotal * 10 + *distArg - '0';
      else {
        switch (*distArg){
          case 'k':
            distArg++;
            if (*distArg != '\0' && *distArg == 'm')
              *meters += currentTotal * 1000;
            else
              return 1;
            break;
          case 'm':
            *meters += currentTotal;
            break;
          default:
            return 1;
        }
        currentTotal = 0;
      }
    }
    distArg++;
  }

  *meters += currentTotal;

  return 0; 
}

int parseDuration(char *durArg, int *seconds){
  int currentTotal; /* buffer that keeps the read digits from the arg */
  short lastIsHour; /* used so that in 2h45, 45 are well interpreted as minutes */

  *seconds = 0;
  currentTotal = 0;
  lastIsHour = 0; 

  while (*durArg != '\0'){
    if (!isspace(*durArg)){ /* just in case that for a reason " or ' are used for the arguments */
      if (isdigit(*durArg))
        currentTotal = currentTotal * 10 + *durArg - '0';
      else {
        switch (*durArg){
          case 'h':
            *seconds += currentTotal * 3600;
            lastIsHour = 1;
            break;
          case 'm':
            *seconds += currentTotal * 60;
            lastIsHour = 0;
            break;
          case 's':
            *seconds += currentTotal;
            break;
          default:
            return 1;
        }
        currentTotal = 0;
      }
    }
    durArg++;
  }

  if (lastIsHour)
    *seconds += currentTotal * 60;
  else
    *seconds += currentTotal;

  return 0;
} 

