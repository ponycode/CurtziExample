//
//  CZSpaceLocation.h
//  Curtzi SDK
//
//  Copyright (c) 2014 PonyCode Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CZSpaceLocation : NSObject

@property (nonatomic, assign, readonly) double latitude;
@property (nonatomic, assign, readonly) double longitude;

@property (nonatomic, strong, readonly) NSString *addressLine1;
@property (nonatomic, strong, readonly) NSString *addressLine2;
@property (nonatomic, strong, readonly) NSString *city;
@property (nonatomic, strong, readonly) NSString *state;
@property (nonatomic, strong, readonly) NSString *zip;

-(NSString*) addressDescription;
-(NSString*) latitudeDescription;
-(NSString*) longitudeDescription;

-(BOOL) hasLatLon;

@end
