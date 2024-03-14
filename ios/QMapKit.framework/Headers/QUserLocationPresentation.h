//
//  QUserLocationPresentation.h
//  QMapKit
//
//  Created by tabsong on 2017/6/26.
//  Copyright © 2017年 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

/**
 * @brief 用户定位罗盘图标自定义样式类
 *        1）显示罗盘方向，四个图片必须全量设置, 且不能为nil
 *        2）隐藏罗盘方向，需将罗盘的四个方向图片同时设置为nil
 */
@interface QUserLocationCompassPresentation : NSObject

/**
 * @brief 罗盘图标.
 */
@property (nonatomic, strong) UIImage *compassImage;

/**
 * @brief 罗盘正北位图片.
 */
@property (nonatomic, strong) UIImage *directionNorth;

/**
 * @brief 罗盘正南位图片.
 */
@property (nonatomic, strong) UIImage *directionSouth;

/**
 * @brief 罗盘正东位图片.
 */
@property (nonatomic, strong) UIImage *directionEast;

/**
 * @brief 罗盘正西位图片.
 */
@property (nonatomic, strong) UIImage *directionWest;

@end

/**
 * @brief 用户导航红线自定义样式类
 */
@interface QNavigationGravityLine : NSObject

/**
 * @brief 导航红线宽度.
 */
@property (nonatomic, assign) CGFloat width;

/**
 * @brief 导航红线颜色.
 */
@property (nonatomic, strong) UIColor *color;

/**
 * @brief 导航红线终点.
 */
@property (nonatomic, assign) CLLocationCoordinate2D destination;

@end


/**
 * @brief 用户定位图标自定义样式类
 */
@interface QUserLocationPresentation : NSObject

/**
 * @brief 定位图标.
 */
@property (nonatomic, strong) UIImage *icon;

/**
 * @brief 定位圈的填充色.
 */
@property (nonatomic, strong) UIColor *circleFillColor;

/**
 * @brief 定位圈罗盘.
 */
@property (nonatomic, strong) QUserLocationCompassPresentation *compass;

/**
 * @brief 定位圈红线.
 */
@property (nonatomic, strong) QNavigationGravityLine *gravityLine;

@end
