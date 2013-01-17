//
//  BHVHook.h
//  Behave
//
//  Created by Ryan Davies on 15/01/2013.
//  Copyright (c) 2013 Ryan Davies. All rights reserved.
//

#import <Foundation/Foundation.h>
@class BHVExample, BHVGroup;

/** Abstract superclass for hooks of varying scope. */
@interface BHVHook : NSObject

/**
 @param example The example to evaluate.
 @return Should return YES for hooks which are to be executed *prior* to an example. */
- (BOOL)isExecutableBeforeExample:(BHVExample *)example;

/**
 @param example The example to evaluate.
 @return Should return YES for hooks which are to be executed *after* an example. */
- (BOOL)isExecutableAfterExample:(BHVExample *)example;

/** Invokes block. */
- (void)execute;

/** The block which contains the implementation of the hook. */
@property (copy, nonatomic) void(^block)(void);

/** The group which this example has been added to. A group is assigned to the example when [BHVGroup addGroup:] is called. */
@property (weak, nonatomic) BHVGroup *parentGroup;

@end
