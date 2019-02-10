#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "LinkedList.h"



void menuREPL(void);

void printBorder(int size, int length);

int inputCheck(int lowerBound, int upperBound, void(*printMenu)());

void printMessage(char *message);

void printMenu(void);

void load(List *listplaylist);

void store(void);

void display(void);

void insert(void);

void delete(void);

void edit(void);

void sort(void);

void rate(void);

void play(void);

void shuffle(void);

void exit(void);

void test(void);