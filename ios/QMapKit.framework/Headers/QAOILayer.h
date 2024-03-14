//
//  QAOILayer.h
//  QMapKit
//
//  Created by Keith Cao on 2020/5/20.
//  Copyright © 2020 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "QGeometry.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief AOILayer 类
 */
@interface QAOILayer : NSObject

/**
 * @brief AOILayer 的id
 */
@property (nonatomic, readonly) NSString *uid;

/**
 * @brief 最小可以显示级别, 添加到地图后无法修改
 */
@property (nonatomic, assign) CGFloat minZoom;

/**
* @brief 最大可以显示级别, 添加到地图后无法修改
*/
@property (nonatomic, assign) CGFloat maxZoom;

/**
 * @brief 隐藏区域面子点
 */
- (void)showSubPois:(BOOL)enable;

/**
 *  @brief AOI 图层初始化接口
 *  @param uid 图层的uid
 */
- (instancetype)initWithUID:(NSString *)uid;

@end

NS_ASSUME_NONNULL_END
