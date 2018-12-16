//  Created by wsy on 2018/10/22.
//  Copyright © 2018 wsy. All rights reserved.
//
#include "Progress.h"

void* createProgress(std::string path, int64_t total) {
    NSProgress *progress = [NSProgress progressWithTotalUnitCount:total];
    progress.kind = NSProgressKindFile;
    progress.pausable = NO;
    progress.cancellable = NO;
    progress.completedUnitCount = 0;
    NSString *p = [NSString stringWithUTF8String:path.c_str()];
    NSURL* dest = [NSURL fileURLWithPath:p];
    [progress setUserInfoObject:dest forKey:NSProgressFileURLKey];
    [progress setUserInfoObject:NSProgressFileOperationKindDownloading forKey:NSProgressFileOperationKindKey];
    [progress publish];
    return (__bridge void*)progress;
}


void updateProgress(void* progress, int64_t current) {
    NSProgress *p = (__bridge id)progress;
    p.completedUnitCount = current;
}
