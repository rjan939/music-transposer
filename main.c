#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_NOTES 12

char *notes[NUM_NOTES] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

// Convert flat to sharp note to simplify a little
char *flat_to_sharp(char *note) {
  if (strcmp(note, "Db") == 0) return "C#";
  if (strcmp(note, "Eb") == 0) return "D#";
  if (strcmp(note, "Fb") == 0) return "E";
  if (strcmp(note, "Gb") == 0) return "F#";
  if (strcmp(note, "Ab") == 0) return "G#";
  if (strcmp(note, "Bb") == 0) return "A#";
  if (strcmp(note, "Cb") == 0) return "B";
  return note;
}

int find_note_index(char *note) {
  for (int i = 0; i < NUM_NOTES; i++) {
    if (strcmp(notes[i], note) == 0) {
      return i;
    }
  }
  return -1;
}

char *transpose_note(char *note, int semitones) {
  note = flat_to_sharp(note);
  int note_index = find_note_index(note);
  if (note_index == -1) {
    printf("Invalid note: %s\n", note);
    exit(1);
  }
  int transposed_index = (note_index + semitones + NUM_NOTES) % NUM_NOTES;
  return notes[transposed_index]; 
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
    char *transposed_note = transpose_note(note, semitones);
    printf("%s ", transposed_note);
  }
  printf("\n");

  return 0;
}
