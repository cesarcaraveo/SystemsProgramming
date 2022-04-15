//
//  main.cpp
//  Lab16
//
//  Created by Cesar Caraveo on 3/2/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include "GroceryCart.h"

// These are sample items. Create your own
// unique items for your shopping cart!
#include "Celery.hpp"
#include "Lettuce.hpp"
#include "ChickenSoup.hpp"

int main(int argc, const char * argv[])
{
    GroceryCart c;
    c.AddItemToCart(new Lettuce(1.2)); // Weight in lbs (Lettuce is $0.49/lb)
    c.AddItemToCart(new Celery(1.5));  // Weight in lbs (Celery is $0.79/lb)
    c.AddItemToCart(new ChickenSoup);
    std::cout << c;
    return 0;
}

// Sample output
// 0.59    lettuce
// 1.19    celery
// 0.99    chicken soup
//-------
//$2.76
