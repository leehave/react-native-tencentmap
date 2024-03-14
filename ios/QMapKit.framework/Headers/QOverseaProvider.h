//
//  QOverseaProvider.h
//  QMapKit
//
//  Created by fan on 2020/6/18.
//  Copyright © 2020 tencent. All rights reserved.
//

#import "QTypes.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
*  @brief     自定义图源的设置类
*
*/
@interface QOverseaProvider : NSObject

/**
*  @brief     名字标识
*
*/
@property (nonatomic, copy ) NSString *name;

/**
*  @brief  tile 构建的下载链接
*
*  @param path     瓦片的标识
*
*/
- (NSString *)URLForTilePath:(QTileOverlayPath)path;

/**
*  @brief    地图样式变化回调
*
*  @param type     地图的样式, 标准或暗色模式
*
*/
- (void)onStyleChanged:(QMapType)type;

/**
*  @brief     此区域的logo
*
*/
- (UIImage *)logoImage;

@end


NS_ASSUME_NONNULL_END
