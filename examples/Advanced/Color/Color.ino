/*

Color Shield Example

This example shows an application on 1Sheeld's color detector shield.

By using this example, you can teach your children colors names by
pointing your smartphone's camera to the color and your smartphone
will say its name using our text-to-speech shield.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_COLOR_DETECTOR_SHIELD
#define INCLUDE_TEXT_TO_SPEECH_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Red Color. */
unsigned long redColor = 0xFF0000;
/* Blue Color. */
unsigned long blueColor = 0x0000FF;
/* Green Color. */
unsigned long greenColor = 0x00FF00;


void setup() {
  /* Start communication. */
  OneSheeld.begin();
  /* Set Palette to get 8 different colors only instead of the default 16 million colors. */
  ColorDetector.setPalette(_3_BIT_RGB_PALETTE);
}

void loop() {
  /* Check if there's a new color received. */
  if(ColorDetector.isNewColorReceived())
  {
    /* Compare colors and if red say red. */
    if(ColorDetector.getLastColor()== redColor)
    {
      /* Say red. */
      TextToSpeech.say("Red");
    }
    else if(ColorDetector.getLastColor()== blueColor)
    {
      /* Say blue. */
      TextToSpeech.say("Blue");
    }
    else if(ColorDetector.getLastColor()== greenColor)
    {
      /* Say green. */
      TextToSpeech.say("Green");
    }
  }
}