//Note Definitions
const int NOTE_AS3 = 233;
const int NOTE_C4 = 262;
const int NOTE_D4 = 294;
const int NOTE_E4 = 330;
const int NOTE_F4 = 349;
const int NOTE_G4 = 392;
const int NOTE_GS4 = 415;
const int NOTE_A4 = 440;
const int NOTE_AS4 = 466;
const int NOTE_B4 = 494;
const int NOTE_C5 = 523;
const int NOTE_CS5 = 554;
const int NOTE_D5 = 587;
const int NOTE_DS5 = 622;
const int NOTE_E5 = 659;
const int NOTE_F5 = 699;
const int NOTE_FS5 = 740;
const int NOTE_G5 = 784;
const int NOTE_GS5 = 831;
const int NOTE_A5 = 880;

const int rhythmBuzzerPin = 9;
const int rhythmLength = 115;

int rhythmNotes[] = {NOTE_A4,0,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,0,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,0,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_C5,NOTE_C5,NOTE_C5,  //Intro 1 (21 Notes)
                    NOTE_A4,0,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,0,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,0,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_C5,NOTE_C5,NOTE_C5,   //Intro 2 (21 Notes)
                    NOTE_A4,NOTE_A4,NOTE_A4,NOTE_F4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_C5,NOTE_A4,                                                                                 //Part 1  (9 Notes)
                    0,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_F5,NOTE_C5,NOTE_GS4,NOTE_F4,NOTE_C5,NOTE_A4,                                                                              //Part 2  (10 Notes)
                    0,NOTE_A5,NOTE_A4,NOTE_A4,NOTE_A5,NOTE_GS5,NOTE_G5,NOTE_FS5,NOTE_F5,NOTE_FS5,                                                                            //Part 3  (10 Notes)
                    0,NOTE_AS4,NOTE_DS5,NOTE_D5,NOTE_CS5,NOTE_C5,NOTE_B4,NOTE_C5,                                                                                            //Part 4  (8 Notes)
                    0,NOTE_F4,NOTE_GS4,NOTE_F4,NOTE_A4,NOTE_C5,NOTE_A4,NOTE_C5,NOTE_E5,                                                                                      //Part 5  (9 Notes)
                    0,NOTE_A5,NOTE_A4,NOTE_A4,NOTE_A5,NOTE_GS5,NOTE_G5,NOTE_FS5,NOTE_F5,NOTE_FS5,                                                                            //Part 6  (10 Notes)
                    0,NOTE_AS4,NOTE_DS5,NOTE_D5,NOTE_CS5,NOTE_C5,NOTE_B4,NOTE_C5,                                                                                            //Part 7  (8 Notes)
                    0,NOTE_F4,NOTE_GS4,NOTE_F4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_C5,NOTE_A4};                                                                                     //Part 8  (9 Notes)

int rhythmBeats[] = {1,2,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,1,   //Intro 1
                    1,2,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,1,    //Intro 2
                    4,4,4,3,1,4,3,1,4,                            //Part 1       
                    4,4,4,4,3,1,4,3,1,4,                          //Part 2
                    4,4,3,1,4,3,1,1,1,1,                          //Part 3
                    3,2,4,3,1,1,1,1,                              //Part 4 
                    3,2,4,3,1,4,3,1,4,                            //Part 5
                    3,4,3,1,4,3,1,1,1,1,                          //Part 6
                    3,2,4,3,1,1,1,1,                              //Part 7 
                    3,2,4,3,1,4,3,1,4};                           //Part 8

int tempo = 150;

void setup() 
{
  pinMode(rhythmBuzzerPin, OUTPUT);
}

void loop() 
{
  int i, rhythmDuration;
  
  for (i = 0; i < rhythmLength; i++) // step through the song arrays
  {
    rhythmDuration = rhythmBeats[i] * tempo;  // length of note/rest in ms
    
    if (rhythmNotes[i] == '0')          // is this a rest? 
    {
      delay(rhythmDuration);            // then pause for a moment
    }
    
    else                          // otherwise, play the note
    {
      tone(rhythmBuzzerPin, rhythmNotes[i], rhythmDuration);
      delay(rhythmDuration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
  
  while(true){}
}

  
   
 
