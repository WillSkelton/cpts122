#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "LinkedList.h"

#define TIMESCALE 1/100



void menuREPL(void);

void printBorder(int size, int length);

int inputCheck(int lowerBound, int upperBound, void(*printMenu)());

void printMessage(char *message);

void printMenu(void);

void load(List *listplaylist, FILE *infile);

void parseLine(Node *tempRecord, char line[100]);

void store(List *playlist);

void display(List *playlist);

void printDisplayOptions(void);

void insert(void);

void del(List *playlist);

Node* findSongBySongName(List *playlist);

void edit(List *playlist);

void printAttributes(void);

void sort(void);

Node* findSongByArtist(List *playlist);

void rate(List *playlist);

void printStarOptions(void);

void play(List *playlist);

void loadingBar(int time);

void shuffle(void);

void exit(void);

void test(void);