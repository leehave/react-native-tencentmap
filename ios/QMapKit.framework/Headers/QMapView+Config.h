//
//  QMapView+Config.h
//  QMapKit
//
//  Created by Zhang Tian on 2018/5/9.
//  Copyright © 2018年 tencent. All rights reserved.
//

#import <QMapKit/QMapKit.h>
#import "QOverseaProvider.h"

@class QTrafficStyle;

/**
 * @brief 地图View的配置.
 */
@interface QMapConfig : NSObject

/**
 * @brief 附加 appId, 这里目前是为小程序提供, 传入小程序的 appId.
 */
@property (nonatomic, copy, readonly) NSString *subID;

/**
 * @brief 附加 key, 这里目前是为小程序提供, 需要小程序开发者传入申请的 key.
 */
@property (nonatomic, copy, readonly) NSString *subKey;

/**
 * @brief 附加 地图字体, nil则使用默认字体
 */
@property (nonatomic, copy) NSString *mapFont;

/**
 * @brief 自定义配置
 */
@property (nonatomic, copy) NSDictionary *preset;

/**
 * @brief 配置其它的海外图源, 默认为0使用内置
 */
@property (nonatomic, assign) int overseaSourceType;

/**
 *	@brief 自定义路况样式配置项
 */
@property (nonatomic, strong) QTrafficStyle *trafficStyle;

/**
 *  @brief 是否启动MSAA，默认为NO
 */
@property (nonatomic, assign) BOOL enableMSAA;

/**
 * @brief 初始化 QMapConfig.
 *
 * @param subID  附加 appId.
 * @param subKey 附加 key.
 * @return QMapConfig 对象.
 */
- (instancetype)initWithSubID:(NSString *)subID subKey:(NSString *)subKey;

@end

/**
 * @brief 地图View的配置相关API.
 */
@interface QMapView (Config)

/**
 * @brief 初始化 QMapView
 *
 * @param frame  QMapView 的 frame 矩形.
 * @param config QMapView 的配置属性.
 * @return QMapView 对象.
 */
- (instancetype)initWithFrame:(CGRect)frame config:(QMapConfig *)config;

/**
* @brief 切换自定义图源
*
* @param provider  自定义的图源
*/
- (void)setOverseaSource:(QOverseaProvider*)provider;

@end

/**
 *	@brief 自定义路况样式
 */
@interface QTrafficStyle : NSObject

/// 交通顺畅配色
@property (nonatomic, strong) UIColor *smoothColor;

/// 交通顺畅描边配色
@property (nonatomic, strong) UIColor *smoothBorderColor;

/// 交通缓慢配色
@property (nonatomic, strong) UIColor *slowColor;

/// 交通缓慢描边配色
@property (nonatomic, strong) UIColor *slowBorderColor;

/// 交通拥堵配色
@property (nonatomic, strong) UIColor *congestedColor;

/// 交通拥堵描边配色
@property (nonatomic, strong) UIColor *congestedBorderColor;

/// 交通非常拥堵配色
@property (nonatomic, strong) UIColor *seriouseCongestedColor;

/// 交通非常拥堵描边配色
@property (nonatomic, strong) UIColor *seriouseCongestedBorderColor;

/// 描边宽度
@property (nonatomic, assign) int borderWidth;

/// 线宽度
@property (nonatomic, assign) int lineWidth;

@end

