//
//  CZTag.h
//  CurtziCore
//
//  Created by Scott Eklund on 2/10/15.
//  Copyright (c) 2015 PonyCode Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM( NSInteger, CZProximity ){
	CZProximityImmediate = 0,
	CZProximityNear = 1,
	CZProximityFar = 2,
	CZProximityUnknown = 99,
	CZProximityOut = 100		// Corrects the Apple SDK's poor enumeration type
};

extern NSInteger const CurtziBeaconOutOfRangeRSSI;		// Large negative value for RSSI when out of range


@interface CZTag : NSObject

@property (nonatomic,assign,readonly) NSInteger rssi;
@property (nonatomic,assign,readonly) CZProximity proximity;
@property (nonatomic,assign,readonly) UInt16 major;
@property (nonatomic,assign,readonly) UInt16 minor;
@property (nonatomic,strong,readonly) NSString *uuid;

-(NSComparisonResult) compareProximity:(CZTag*) otherTag;

-(NSString*) proximityString;

@end

