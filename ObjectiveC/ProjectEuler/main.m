//
//  main.m
//  ProjectEuler
//
//  Created by Pete Jensen on 6/4/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

// ****
// Problem
// 
// interface
@interface Problem : NSObject

@property int number;
-(void) compute;

@end

// implementation
@implementation Problem

-(void) compute
{
    NSLog(@"Solving problem %d", self.number);
}

@synthesize number;

- (id)init {
    self = [super init];
    if (self) {
        [self setNumber:0];
    }
    return self;
}

- (id)initWithNumber:(int)n {
    
    if ([self number] == 0) {
        @throw @"Cannot call initWithNumber with 0";
    }
    
    self = [super init];
    [self setNumber:n];
    return self;
}

@end
//

// ****
// Problem14
@interface Problem14 : Problem
{
@public
    int count,start;
}

-(void) compute;

@end

@implementation Problem14

- (void) compute {
    [super compute];
}

- (id)init {
    self = [super initWithNumber:0];
    return self;
}
@end
//

int main (int argc, const char * argv[])
{
    @autoreleasepool {
        
        // insert code here...
        NSLog(@"Hello, World!");
                
        Problem14 *p14 = [[Problem14 alloc] init];

    }
        
    return 0;
}
