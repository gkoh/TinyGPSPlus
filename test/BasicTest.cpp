#include <cstdio>

#include <TinyGPSPlus.h>
/*
   This sample sketch should be the first you try out when you are testing a TinyGPSPlus
   (TinyGPSPlus) installation.  In normal use, you feed TinyGPSPlus objects characters from
   a serial NMEA GPS device, but this example uses static strings for simplicity.
*/

// A sample NMEA stream.
const char *gpsStream =
    "$GPRMC,045103.000,A,3014.1984,N,09749.2872,W,0.67,161.46,030913,,,A*7C\r\n"
    "$GPGGA,045104.000,3014.1985,N,09749.2873,W,1,09,1.2,211.6,M,-22.5,M,,0000*62\r\n"
    "$GPRMC,045200.000,A,3014.3820,N,09748.9514,W,36.88,65.02,030913,,,A*77\r\n"
    "$GPGGA,045201.000,3014.3864,N,09748.9411,W,1,10,1.2,200.8,M,-22.5,M,,0000*6C\r\n"
    "$GPRMC,045251.000,A,3014.4275,N,09749.0626,W,0.51,217.94,030913,,,A*7D\r\n"
    "$GPGGA,045252.000,3014.4273,N,09749.0628,W,1,09,1.3,206.9,M,-22.5,M,,0000*6F\r\n";

// The TinyGPSPlus object
TinyGPSPlus gps;

void displayInfo() {
  printf("Location: ");

  if (gps.location.isValid()) {
    printf("%03.3f, %03.3f", gps.location.lat(), gps.location.lng());
  } else {
    printf("INVALID");
  }

  printf("  Date/Time: ");
  if (gps.date.isValid()) {
    printf("%u/%u/%hu", gps.date.month(), gps.date.day(), gps.date.year());
  } else {
    printf("INVALID\n");
  }

  if (gps.time.isValid()) {
    printf("  %02u:%02u:%02u.%02u\n", gps.time.hour(), gps.time.minute(), gps.time.second(),
           gps.time.centisecond());
  } else {
    printf(" INVALID\n");
  }
}

int main(void) {
  printf("BasicTest\n");

  while (*gpsStream)
    if (gps.encode(*gpsStream++))
      displayInfo();

  printf("Done.");
}
