//
//  Food.h
//  NOC_9_05_EvolutionEcosystem
//
//  Created by Greg Kepler on 2/18/14.
//
//

#pragma once

#include "cinder/app/AppNative.h"

class Food
{
	std::vector<ci::Vec2f> mFood;
	
public:
	Food( int num );
	void					add( ci::Vec2f l );
	void					run();
	std::vector<ci::Vec2f>*	getFood();
};