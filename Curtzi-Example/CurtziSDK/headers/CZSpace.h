//
//  CZSpace.h
//  Curtzi SDK
//
//  Copyright (c) 2014 PonyCode Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CZSpaceLocation.h"

@protocol CZSpaceObserver;

typedef NS_ENUM( NSInteger, CZProximity ){
	CZProximityImmediate = 0,
	CZProximityNear = 1,
	CZProximityFar = 2,
	CZProximityUnknown = 99,
	CZProximityOut = 100		// Corrects the Apple SDK's poor enumeration type
};



@interface CZSpace : NSObject

@property (nonatomic,readonly,strong) NSString *name;

@property (nonatomic,readonly,strong) CZSpaceLocation *location;

@property (nonatomic,readonly,assign) NSInteger rssi;
@property (nonatomic,readonly,assign) CZProximity proximity;

@property (nonatomic,readonly,assign) NSInteger major;				// iBeacon Major (16bits)
@property (nonatomic,readonly,assign) NSInteger minor;				// iBeacon Minor (16bits)
@property (nonatomic,readonly,strong) NSString *uuid;

-(NSComparisonResult) compareProximity:(CZSpace*) otherSpace;		// compares spaces by proximity of beacon (Ascending distance)

/*
 WARNING: This is a provisional method and it may be deprecated at a later date
 */

-(NSDictionary*) passbookBeaconDictionaryWithRelevantText:(NSString*) relevantText;

-(NSString*) proximityString;

@end


@protocol CZSpaceObserver <NSObject>

-(void) spaceDidUpdateRange:(CZSpace*)space;

@end