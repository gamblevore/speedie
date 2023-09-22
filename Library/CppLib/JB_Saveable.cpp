
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2017 Theodore H. Smith.
*/


#include "JB_Umbrella.h"
#include <stdio.h>

extern "C" {

//struct Saveable;
Saveable* JB_Sav_Constructor(Saveable* self) {
//	JB_New2(Saveable); // doesnt need to do anything
	return self;
}

}


