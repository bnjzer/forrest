# Forrest
*(because "Run Forrest, run!")*

## Description

Given a distance and a duration, it computes all the time targets for your race.
By default, if the distance is smaller than 5km, time targets are printed every 200m
and otherwise every 1km, but this is configurable.

## Usage

```
Usage: ./bin/forrest <distance> <duration> [step]
  - distance examples : 3km, 200m, 3km500, 1500m, 400 (default unit: meter)
  - duration examples : 1h27m4, 27m, 2h3, 1h45s, 30 (default unit: second)
  - step : step used to print the times targets. Same format as distance
           default: 200m if the distance is <= 5km and 1km otherwise
```

To compile : ```$ make```

To launch : ```$ ./bin/forrest```

To compile and launch cunit tests : ```$ make test```

## Examples

### Example 1 (> 5km)

```
$ ./bin/forrest 21km 1h15
speed: 16.80 km/h

      1 km : 0:03:34
      2 km : 0:07:08
      3 km : 0:10:42
      4 km : 0:14:17
      5 km : 0:17:51
      6 km : 0:21:25
      7 km : 0:25:00
      8 km : 0:28:34
      9 km : 0:32:08
     10 km : 0:35:42
     11 km : 0:39:17
     12 km : 0:42:51
     13 km : 0:46:25
     14 km : 0:50:00
     15 km : 0:53:34
     16 km : 0:57:08
     17 km : 1:00:42
     18 km : 1:04:17
     19 km : 1:07:51
     20 km : 1:11:25
     21 km : 1:15:00
```

### Example 2 (< 5km)

```
$ ./bin/forrest 4km 20m
speed: 12.00 km/h

     200 m : 0:01:00
     400 m : 0:02:00
     600 m : 0:03:00
     800 m : 0:04:00
      1 km : 0:05:00
    1.2 km : 0:06:00
    1.4 km : 0:07:00
    1.6 km : 0:08:00
    1.8 km : 0:09:00
      2 km : 0:10:00
    2.2 km : 0:11:00
    2.4 km : 0:12:00
    2.6 km : 0:13:00
    2.8 km : 0:14:00
      3 km : 0:15:00
    3.2 km : 0:16:00
    3.4 km : 0:17:00
    3.6 km : 0:18:00
    3.8 km : 0:19:00
      4 km : 0:20:00
```

### Example 3 (> 5km with defined step)

```
$ ./bin/forrest 10km 1h 500
speed: 10.00 km/h

     500 m : 0:03:00
      1 km : 0:06:00
    1.5 km : 0:09:00
      2 km : 0:12:00
    2.5 km : 0:15:00
      3 km : 0:18:00
    3.5 km : 0:21:00
      4 km : 0:24:00
    4.5 km : 0:27:00
      5 km : 0:30:00
    5.5 km : 0:33:00
      6 km : 0:36:00
    6.5 km : 0:39:00
      7 km : 0:42:00
    7.5 km : 0:45:00
      8 km : 0:48:00
    8.5 km : 0:51:00
      9 km : 0:54:00
    9.5 km : 0:57:00
     10 km : 1:00:00
```
