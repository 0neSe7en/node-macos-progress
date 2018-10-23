//
//  Progress.h
//  node-macos-progress
//
//  Created by wsy on 2018/10/22.
//  Copyright © 2018 wsy. All rights reserved.
//

#ifndef Progress_h
#define Progress_h

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#endif
#include <string>
#include <iostream>
void* createProgress(std::string path, int64_t total);
void updateProgress(void* progress, int64_t current);
#endif /* Progress_h */
