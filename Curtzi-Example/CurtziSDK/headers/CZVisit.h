//
//  CZVisit.h
//  Curtzi SDK
//
//  Created by Josh Kennedy on 3/25/14.
//  Copyright (c) 2014 PonyCode Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CZVisitLocation.h"
#import "CZTag.h"


@protocol CZVisitObserver;


@interface CZVisit : NSObject

@property (nonatomic, strong, readonly) CZTag *tag;

@property (nonatomic, strong, readonly) NSString *name;

@property (nonatomic, strong, readonly) CZVisitLocation *location;
@property (nonatomic, assign, readonly) CZProximity proximity;
@property (nonatomic, strong, readonly) NSDate *visitStart;
@property (nonatomic, strong, readonly) NSDate *visitEnd;
@property (nonatomic, assign, readonly) NSTimeInterval visitDuration;
@property (nonatomic, strong, readonly) NSDate *visitLastUpdated;
@property (nonatomic, assign, readonly) BOOL isVisiting;				// YES while visiting, NO after exiting

@property (nonatomic, strong, readonly) NSArray *tagKeywords;			// keywords attached to tag by its owner
@property (nonatomic, strong, readonly) NSArray *matchedTagKeywords;	// those keywords from the visit that match our app

-(void) addObserver:(id<CZVisitObserver>) observer;						// observe changes to this Space (creates weak reference)
-(void) removeObserver:(id<CZVisitObserver>) observer;

-(BOOL) isEqual:(id)object;

+(NSArray*) visitsSortedByProximity:(NSArray*)visits;
+(NSArray*) visitsSortedByStartTime:(NSArray*)visits;

-(NSComparisonResult) compareProximity:(CZVisit*)otherVisit;

@end


@protocol CZVisitObserver <NSObject>

-(void) visitDidUpdate:(CZVisit*)visit;

@end
