#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_NOTES 12

char *notes[NUM_NOTES] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
char *flats[NUM_NOTES] = {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};

int find_note_index(char *note) {
  for (int i = 0; i < NUM_NOTES; i++) {
    if ((strcmp(notes[i], note) == 0) || (strcmp(flats[i], note)) == 0) 
      return i; 
  }
  return -1;
}

char *transpose_note(char *note, int semitones, bool flat) {
  int note_index = find_note_index(note);
  if (note_index == -1) {
    printf("Invalid note: %s\n", note);
    exit(1);
  }
  int transposed_index = (note_index + semitones + NUM_NOTES) % NUM_NOTES;
  return (flat) ? flats[transposed_index] : notes[transposed_index]; 
}


bool is_num(char number[]) {
  int i = 0;
  if (number[0] == '-')
    i = 1;
  for (; number[i] != 0; i++) {
    if (!isdigit(number[i]))
      return false;
  }
  return true;
}

int main(int argc, char **argv) {
  int semitones;
  int start = 1;
  if (argc == 1) {
    printf("Usage : ./transpose <notes> \n");
    exit(1);
  }
  if (is_num(argv[1])) {
    if (argc == 2) {
      printf("Usage : ./transpose <semitones> <notes>\n");
      return 1;
    }
    semitones = atoi(argv[1]);
    start = 2;
  } else {
    printf("Enter the number of semitones to transpose: ");
    scanf("%d", &semitones);
    start = 1;
  }

  printf("Transposed sequence: ");
  for (int i = start; i < argc; i++) {
    char *note = argv[i];
    bool flat = false;
    if (note[1] == 'b')
      flat = true;
    char *transposed_note = transpose_note(note, semitones, flat);
    printf("%s ", transposed_note);
  }
  printf("\n");

  return 0;
}
