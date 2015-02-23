//
//  CurtziExampleViewController.m
//  Curtzi-Example
//

#import "CurtziExampleViewController.h"
#import "Curtzi.h"


@interface CurtziExampleViewController ()<CurtziObserver>

@property (weak, nonatomic) IBOutlet UILabel *sdkVersionLabel;
@property (weak, nonatomic) IBOutlet UILabel *sdkConnectivityStatusLabel;
@property (weak, nonatomic) IBOutlet UILabel *visitInformationLabel;
@property (weak, nonatomic) IBOutlet UIButton *bestFeatureEverButton;

@property (nonatomic, strong) NSMutableArray *curtziVisits;
@property (nonatomic, assign) BOOL isBestFeatureEverEnabled;

@end


@implementation CurtziExampleViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	
	self.curtziVisits = [NSMutableArray arrayWithArray:[Curtzi visits]];
	[self showMostRecentCurtziVisit];

#if TARGET_IPHONE_SIMULATOR
	self.sdkConnectivityStatusLabel.text = @"Location unavailable on simulator";
	self.bestFeatureEverButton.enabled = NO;
#else
	self.sdkConnectivityStatusLabel.text = [self connectivityMessage:[Curtzi connectivity]];
	[Curtzi addCurtziObserver:self];
#endif
	
	self.isBestFeatureEverEnabled = [Curtzi connectivity].locationIsAuthorized;
	
	self.sdkVersionLabel.text = [NSString stringWithFormat:@"Curtzi SDK Version:%@", [Curtzi version]];
	
}

#pragma UX for Location Feature

-(void) setIsBestFeatureEverEnabled:(BOOL)isBestFeatureEverEnabled;
{
	_isBestFeatureEverEnabled = isBestFeatureEverEnabled;
	
	if( _isBestFeatureEverEnabled ){
		self.visitInformationLabel.hidden = NO;
		self.bestFeatureEverButton.hidden = YES;
	} else {
		self.visitInformationLabel.hidden = YES;
		self.bestFeatureEverButton.hidden = NO;
	}
}

- (IBAction)didClickBestFeatureEverButton:(UIButton *)sender {
	// Authorization will be prompted for unless it's already granted
	[Curtzi authorizeLocationServices:CZLocationServicesAuthorizationTypeAll];
}

#pragma mark UX for Connectivity State

-(NSString*) connectivityMessage:(CZConnectivity*)connectivity;
{
	if( !connectivity.locationIsAuthorized ){
		return @"Location Sharing needed for Best Feature Ever";
	}
	
	if ( !connectivity.bluetoothIsActive ){
		return  @"Bluetooth needed for Best Feature Ever";
	}
	
	return @"Ready";
}

#pragma mark Curtzi Observer Methods

-(void) curtziConnectivityDidChange:(CZConnectivity *)connectivity;
{
	self.sdkConnectivityStatusLabel.text = [self connectivityMessage:connectivity];
	self.isBestFeatureEverEnabled = connectivity.locationIsAuthorized;
	self.visitInformationLabel.hidden = ! (connectivity.curtziIsCurrentlySupported);
}

-(void) curtziDidBeginVisit:(CZVisit*) visit;
{
	[self.curtziVisits insertObject:visit atIndex:0];
	[self showMostRecentCurtziVisit];
}

-(void) curtziDidEndVisit:(CZVisit*) visit;
{
	[self.curtziVisits removeObject:visit];
	[self showMostRecentCurtziVisit];
}

#pragma UX for Curtzi Visits

-(void) showMostRecentCurtziVisit;
{
	if( [self.curtziVisits count] ){
		CZVisit *mostRecentVisit = (CZVisit*)[self.curtziVisits objectAtIndex:0];
		self.visitInformationLabel.text = mostRecentVisit.name;
	} else {
		self.visitInformationLabel.text = @"Looking for Curtzi Tags";
	}
}
@end
