//
//  QTypes.h
//  QMapKit
//
//  Created by fan on 2017/6/24.
//  Copyright © 2017年 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef QTypes_h
#define QTypes_h

// 地图鉴权错误
FOUNDATION_EXPORT NSErrorDomain const QMapAuthenticationErrorDomain;

// 地图鉴权错误码.
NS_ERROR_ENUM(QMapAuthenticationErrorDomain)
{
    // 鉴权内部错误.
    QMapAuthenticationErrorInternal = 1001,
};

/**
 *  @brief  底图内容的类型. 默认为QMapTypeStandard
 */
typedef NS_ENUM(NSUInteger, QMapType) {
    QMapTypeStandard = 0,       ///<标准地图
    QMapTypeSatellite,          ///<卫星地图
    QMapTypeDark                ///<暗色模式地图
};


typedef NS_ENUM (int, QMapStyleType) {
    QMapStyle_Normal            = 0,    // normal
    QMapStyle_Navigation        = 1,    // navigation
    QMapStyle_NavigationNight   = 2     // dark
} DEPRECATED_ATTRIBUTE;

/** @enum QMapLanguage 海外图的语言
 * @brief 海外图文字标注的首选语言
 */
typedef NS_ENUM(NSUInteger, QMapLanguage) {
    QMapLanguage_zh = 0,    ///< 中文
    QMapLanguage_en         ///< 英语
};

/** @enum QMapLanguage 地图标注大小
 * @brief 底图文字标注的大小
 */
typedef NS_ENUM(NSInteger, QMapLabelSize) {
    QMapLabelSize_Tiny = 0,     ///< 特小
    QMapLabelSize_Small,        ///< 小
    QMapLabelSize_Normal,       ///< 标准
    QMapLabelSize_Large,        ///< 大
    QMapLabelSize_Huge          ///< 特大
};

/**
 * @brief 代表单个瓦片的索引
 */
typedef struct {
    NSInteger x;    ///< 瓦片的x下标
    NSInteger y;    ///< 瓦片的y下标
    NSInteger z;    ///< 瓦片所在缩放级别
    NSInteger     language;       // language. 1:en, 0:zh
    double contentScaleFactor; ///< 暂不支持
} QTileOverlayPath;

/**
 * @brief 覆盖物的显示级别，决定了与POI等地理元素的压盖关系
 */
typedef NS_ENUM(NSInteger, QOverlayLevel) {
    QOverlayLevelAboveRoads = 0,    // 在道路之上楼块之下
    QOverlayLevelAboveBuildings,    // 在楼块之上POI之下
    QOverlayLevelAboveLabels        // 显示在所有POI之上
};

/**
 * @brief 限制区域显示的限制方式，分别以区域宽度为参考值和以区域高度为参考值
 */
typedef NS_ENUM(NSInteger,QMapLimitRectFitMode) {
    QMapLimitRectFitWidth = 0,  // 此模式会以 mapRect宽度为参考值限制地图的控制区域，保证横向区域完全展示
    QMapLimitRectFitHeight      // 此模式会以 mapRect高度为参考值限制地图的控制区域，保证纵向区域完全展示
};


/**
 *	@brief 多边形/圆 的描边样式
 */
typedef NS_ENUM(NSUInteger, QOverlayStrokeType) {
    QOverlayStrokeType_Default,		/// 实线
    QOverlayStrokeType_Dash,		/// 长方块虚线
    QOverlayStrokeType_Dot,			/// 圆点虚线
};

/**
 *    @brief 手势类型
 */
typedef NS_ENUM(NSUInteger, QGestureType) {
    QGestureType_Move = 1,          /// 移动
    QGestureType_ZoomIn,            /// 放大
    QGestureType_ZoomOut,           /// 缩小
    QGestureType_Pinch,             /// 捏合缩放
    QGestureType_SingleFingerZoom,  /// 单指缩放
    QGestureType_Rotate,            /// 旋转
    QGestureType_Pitch,             /// 倒伏
    QGestureType_SingleTap,         /// 点击
    QGestureType_Butt               /// 边界，自身非手势
};



#endif /* QTypes_h */
