//
//  QHeatNodeProcotol.h
//  QMapKit
//
//  Created by fan on 2020/3/9.
//  Copyright © 2020 tencent. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  @brief 协议类。用于提供生成热力图时需要的数据
 */
@protocol QHeatNodeProtocol <NSObject>

@required

/**
 *  @brief  坐标.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

/**
 *  @brief  热力值.
 */
@property (nonatomic, readonly) CGFloat value;

@end

/**
 * @brief 热力图节点数据
 */
@interface QHeatNode : NSObject <QHeatNodeProtocol>

/**
 *  @brief  节点的坐标.
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 *  @brief  节点的热力值.
 */
@property (nonatomic, assign) CGFloat value;

@end


NS_ASSUME_NONNULL_END
