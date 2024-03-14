//
//  QMapView.h
//  QMapKit
//
//  Created by tabsong on 17/5/15.
//  Copyright © 2017年 tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "QGeometry.h"
#import "QAnnotation.h"
#import "QAnnotationView.h"
#import "QOverlayView.h"
#import "QBasicMapViewLayer.h"
#import "QTypes.h"
#import "QUserLocationPresentation.h"
#import "QTileOverlay.h"
#import "QCustomLayer.h"
#import "QAOILayer.h"
#import "QText.h"

typedef NS_ENUM(NSInteger, QUserTrackingMode)
{
    QUserTrackingModeNone              = 0,    ///< 不追踪用户的location更新
    QUserTrackingModeFollow            = 1,    ///< 追踪用户的location更新
    QUserTrackingModeFollowWithHeading = 2     ///< 追踪用户的location与heading更新
};

typedef NS_ENUM(NSUInteger, QMapLogoAnchor)
{
    QMapLogoAnchorRightBottom   = 0,    ///< 右下对齐, logo的对齐位置, 默认锚点位置
    QMapLogoAnchorLeftBottom,           ///< 左下对齐
    QMapLogoAnchorLeftTop,              ///< 左上对齐
    QMapLogoAnchorRightTop,             ///< 右上对齐
    QMapLogoAnchorMax                   ///< 边界, 自身无实际意义
};

@class QUserLocation;
@protocol QMapViewDelegate;


#pragma mark - QMapView

/**
 *  @brief  地图view的核心类
 */
@interface QMapView : UIView

/**
 *  @brief  是否开启手绘图，默认为 NO
 *
 * @notes 打开手绘图会将最大级别限制为19
 */
@property (nonatomic, assign, getter = isHandDrawMapEnabled) BOOL handDrawMapEnabled;

/**
 *  @brief  是否开启路况图，默认为 NO
 */
@property (nonatomic, assign) BOOL showsTraffic;

#pragma mark - Resources

/**
 * @brief  使用用户传入的地图资源文件(在地图初始化前调用)
 *
 * @param path 资源文件存放目录的全路径
 */
+ (void)loadPrefferedResourceFilesFromDirectory:(NSString *)path DEPRECATED_ATTRIBUTE;

#pragma mark - Basic

/**
 *  @brief 地图回调
 */
@property (nonatomic, weak) id<QMapViewDelegate> delegate;

/*@
 *  @brief  地图类型
 */
@property (nonatomic, assign) QMapType mapType;


/**
 * @brief  设置底图样式，默认为标准样式.
 *
 * @param styleType 用户自定义配置的样式序号.
 *
 * @notes 已弃用, 请使用setMapStyle
 */
- (void)setStyleType:(QMapStyleType)styleType DEPRECATED_ATTRIBUTE;

/**
 * @brief 改变底图样式
 *
 * @notes 值为在官网配置的自定义样式列表中的顺序, 从1开始
 */
- (void)setMapStyle:(int)styleType;

/**
 *  @brief  是否显示比例尺，默认为YES
 */
@property (nonatomic) BOOL showsScale;

/**
 *  @brief  是否显示建筑物，默认为YES
 */
@property (nonatomic) BOOL showsBuildings;

/**
 *  @brief  是否显示建筑物样式为3D效果，默认为YES
 */
@property (nonatomic) BOOL shows3DBuildings;

/**
 *  @brief  是否显示底图上的标注及名称，默认为YES
 */
@property (nonatomic) BOOL showsPoi;

/**
 *  @brief  设置底图上的标注的字体大小
 *
 *  默认QMapLabelSize_Normal.
 */
@property (nonatomic) QMapLabelSize labelSize;

/**
 *  @brief  是否显示底图，默认为YES
 */
@property (nonatomic) BOOL showsBaseMap;

/**
 *  @brief  是否显示指南针，默认为NO
 */
@property (nonatomic) BOOL showsCompass;

/**
 * @brief	当前地图最大渲染帧数，默认为60
 */
@property (nonatomic) NSInteger preferredFramesPerSecond;

/**
 *  @brief  设置指南针基于默认位置的偏移. 右下为正
 */
- (void)setCompassOffset:(CGPoint)offset;

/**
 * @brief 指定海外图文字的首选语言
 *
 * 指定海外图文字的语言，默认采用中文
 *
 * @param language 指定的语言
 * @see QMapLanguage
 */
- (void)setForeignLanguage:(QMapLanguage)language;

/**
 * @brief 是否打开世界图
 */
- (void)setWorldMapEnable:(BOOL)enable;

/**
 *  @brief 设置中心点偏移，向下为正. 单位：比例值(-0.25 ~ 0.25)默认为0
 */
- (void)setCenterOffsetY:(float)offset __attribute__ ((deprecated("use - (void)setCenterOffsetV2:(CGPoint)offset animated:(BOOL)animated instead")));

/**
 *  @brief 设置中心点偏移，向右向下为增长. 单位：屏幕比例值(0.25 ~ 0.75)默认为(0.5, 0.5)
 */
- (void)setCenterOffset:(CGPoint)offset __attribute__ ((deprecated("use - (void)setCenterOffsetV2:(CGPoint)offset animated:(BOOL)animated instead")));

/**
 *  @brief 设置中心点偏移
 *
 *  @param offset 中心点偏移，向右向下为正. 单位：屏幕比例值(0.25 ~ 0.75)默认为(0.5, 0.5)
 *  @param animated 是否采用动画
 */
- (void)setCenterOffset:(CGPoint)offset animated:(BOOL)animated __attribute__ ((deprecated("use - (void)setCenterOffsetV2:(CGPoint)offset animated:(BOOL)animated instead")));

/**
 * @brief 设置中心点偏移，向右向下为正，默认为(0.5, 0.5)，范围是 [0.05, 0.95]。若超出范围，则被裁减到 [0.05, 0.95]。
 */
@property(nonatomic) CGPoint centerOffsetV2;

/**
 *  @brief 设置中心点偏移
 *
 *  @param offset 中心点偏移，向右向下为正，默认为(0.5, 0.5)，范围是 [0.05, 0.95]。若超出范围，则被裁减到 [0.05, 0.95]。
 *  @param animated 是否采用动画
 */
- (void)setCenterOffsetV2:(CGPoint)offset animated:(BOOL)animated;

/**
 * @brief  设置地图Logo偏移
 *
 * @param offset Logo中心的偏移量. 如果offset为CGPointZero则为默认位置
 */
- (void)setLogoOffset:(CGPoint)offset DEPRECATED_ATTRIBUTE;

/**
 * @brief  设置地图Logo位置和大小. 调用后会覆盖默认位置
 *
 * @param margin 基于指定锚点(近边之间)的边距长度值. 单位Point, 默认为(6, 3)
 * @param anchor Logo基于mapview的位置的基准锚点.
 */
- (void)setLogoMargin:(CGPoint)margin anchor:(QMapLogoAnchor)anchor;

/**
 * @brief  设置地图Logo大小.
 *
 * @param scale Logo大小. 基于原始大小的比例值, 默认为1.0. 有效区间[0.7, 1.3]
 */
- (void)setLogoScale:(CGFloat)scale;


/**
 *	@brief	logo位置，需设置在地图的bounds里
 */
@property (nonatomic, assign) CGPoint logoCenter;

/**
*	@brief	logo的宽高
*/
@property (nonatomic, readonly) CGSize logoSize;

/**
 * @brief  设置地图比例尺偏移
 *
 * @param offset 比例尺的偏移量. 如果offset为CGPointZero则为默认位置
 */
- (void)setScaleViewOffset:(CGPoint)offset;

/**
 *	@brief	比例尺原点位置
 */
@property (nonatomic, assign) CGPoint scaleOrigin;

/**
 *	@brief	比例尺的尺寸
 */
@property (nonatomic, readonly) CGSize scaleSize;

/**
 *	@brief 设置比例尺是否淡出,比例尺只在地图级别变化的时候淡入，并在地图级别停止变化后淡出
 *	@param enable 为true时，比例尺会淡出；为false时，比例尺常驻
 */
- (void) setScaleViewFadeEnable:(BOOL)enable;

/**
 * @brief  设置是否显示封路事件
 *
 * @param visible yes为显示，否则不显示
 */
- (void)setRoadEventVisible:(BOOL)visible DEPRECATED_ATTRIBUTE;

/**
 * @brief 设置不显示建筑物的区域.
 * @param noBuildingList yes为显示，否则不显示
 * @param count 区域个数
 */
- (void)setBuildingBlackList:(QMapRect*)noBuildingList count:(int)count;

/**
 * @brief 地图动画Layer.
 * 使用该layer 可以更灵活的组合 {centerCoordinate, zoomLevel, rotation, overlooking} 动画，
 * 并且可以自定义其duration, timingFunction 等CoreAnimation所支持的一切动画属性.
 */
@property (nonatomic, readonly) QBasicMapViewLayer *animationLayer;

#pragma mark - MapStatus

/**
 *  @brief  中心点经纬度
 */
@property (nonatomic, assign) CLLocationCoordinate2D centerCoordinate;

/**
 *  @brief  设置中心点经纬度
 *
 *  @param coordinate  中心点经纬度
 *  @param animated 是否采用动画
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated;

/**
 *  @brief  缩放级别, 范围 [minZoomLevel, maxZoomLevel]
 */
@property (nonatomic, assign) CGFloat zoomLevel;

/**
 *  @brief  最小缩放级别, 默认 minZoomLevel = 3
 */
@property (nonatomic, readonly) CGFloat minZoomLevel;

/**
 *  @brief  最大缩放级别, 默认 maxZoomLevel = 20
 */
@property (nonatomic, readonly) CGFloat maxZoomLevel;

/**
 *  @brief  设置最小最大缩放级别, 范围 3 <= minZoomLevel <= maxZoomLevel <= 20
 *
 *  @param minZoomLevel 最小缩放级别
 *  @param maxZoomLevel 最大缩放级别
 */
- (void)setMinZoomLevel:(CGFloat)minZoomLevel maxZoomLevel:(CGFloat)maxZoomLevel;

/**
 *  @brief  设置缩放级别
 *
 *  @param zoomLevel  缩放级别
 *  @param animated 是否采用动画
 */
- (void)setZoomLevel:(CGFloat)zoomLevel animated:(BOOL)animated;

/**
 *  @brief  旋转角度, 正角度向右转, 单位(角度)
 */
@property (nonatomic, assign) CGFloat rotation;

/**
 *  @brief  设置旋转角度, 正角度向右转, 单位(角度)
 *
 *  @param rotation  旋转角度
 *  @param animated 是否采用动画
 */
- (void)setRotation:(CGFloat)rotation animated:(BOOL)animated;

/**
 *  @brief  Overlooking, 范围 [0, 45], 单位(角度)
 */
@property (nonatomic, assign) CGFloat overlooking;

/**
 *  @brief  允许最大俯仰角跟随缩放级别变化
 *  @param  enable 是否打开
 */
- (void)enableAutoMaxOverlooking:(BOOL)enable;

/**
 *  @brief  设置overlooking, 范围 [0, 45], 单位(角度)
 *
 *  @param overlooking  overlooking
 *  @param animated 是否采用动画
 */
- (void)setOverlooking:(CGFloat)overlooking animated:(BOOL)animated;

/**
 *  @brief  当前地图可见范围的mapRect
 */
@property (nonatomic) QMapRect visibleMapRect;

/**
 *  @brief  设置当前地图可见范围的mapRect
 *
 *  @param mapRect  目标mapRect
 *  @param animated 是否采用动画
 */
- (void)setVisibleMapRect:(QMapRect)mapRect animated:(BOOL)animated;

/**
 *  @brief  设置当前地图可见范围的mapRect
 *
 *  @param mapRect  目标mapRect
 *  @param insets   要嵌入的边界
 *  @param animated 是否采用动画
 */
- (void)setVisibleMapRect:(QMapRect)mapRect edgePadding:(UIEdgeInsets)insets animated:(BOOL)animated;

/**
 *  @brief  当前地图的经纬度范围，设定的该范围可能会被调整为适合地图窗口显示的范围
 */
@property (nonatomic) QCoordinateRegion region;

/**
 *  @brief  设定当前地图的region
 *
 *  @param region   要设定的地图范围，用经纬度的方式表示
 *  @param animated 是否采用动画
 */
- (void)setRegion:(QCoordinateRegion)region animated:(BOOL)animated;

/**
 *  @brief  设定当前地图的region
 *
 *  @param region   要设定的地图范围，用经纬度的方式表示
 *  @param insets   要嵌入的边界
 *  @param animated 是否采用动画
 */
- (void)setRegion:(QCoordinateRegion)region edgePadding:(UIEdgeInsets)insets animated:(BOOL)animated;

/**
 * @brief  根据边界留宽计算合适的地理范围
 * @param mapRect 待调整的地理范围
 * @return 调整后的地图范围
 */
- (QMapRect)mapRectThatFits:(QMapRect)mapRect edgePadding:(UIEdgeInsets)insets;

/**
 * @brief  根据当前地图View的窗口大小调整传入的mapRect，返回适合当前地图窗口显示的mapRect(2D北朝上场景时)
 * @param mapRect 待调整的地理范围
 * @param bContainsCalloutView 计算的maprect是否需要包含calloutView
 * @param annotations 要包含的annotation 数组
 * @param insets mapRect四周要预留的边界大小
 * @return 调整后适合当前地图窗口显示的地图范围
 */
- (QMapRect)mapRectThatFits: (QMapRect)mapRect
        containsCalloutView:(BOOL)bContainsCalloutView
                annotations:(NSArray<id<QAnnotation> >*)annotations
                edgePadding:(UIEdgeInsets)insets;

/**
 * @brief  根据边界留宽及地理范围计算合适的级别(2D北朝上场景时)
 * @param mapRect 待调整的地理范围
 * @param outCoordinate 合适的中心点经纬度.
 * @return 合适的级别
 */
- (CGFloat)zoomLevelThatFits:(QMapRect)mapRect edgePadding:(UIEdgeInsets)insets outCenterCoordinate:(CLLocationCoordinate2D *)outCoordinate;

/**
 * @brief  根据边界留宽显示限制地图区域范围(2D北朝上场景时)
 * @param mapRect 待调整的地理范围
 * @param mode    限制地区区域的对齐方式，分等宽对齐和等高对齐
 * 当传入的mapRect的值都为0时，取消区域限制
 */
-(void)setLimitMapRect:(QMapRect)mapRect mode:(QMapLimitRectFitMode)mode;

/**
 *  @brief 获取当前地图view矩阵
 *  @return 矩阵数组（长度为16）
 */
- (float *)glViewMatrix;

/**
 *  @brief 获取当前地图projection矩阵
 *  @return 矩阵数组（长度为16）
 */
- (float *)glProjectionMatrix;

/**
* @brief 将经纬度坐标转换为OpenGL使用的坐标
* @param coordinate 经纬度坐标
* @return OpenGL坐标系下的坐标
*/
- (CGPoint)glVertexForCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 * @brief  返回每屏幕Point单位对应的OpenGL坐标系下的长度
 * @return OpenGL/屏幕Point 的比例关系
 */
- (CGFloat)glPointRatio;

/**
 * @brief 在当前缩放级别下, 基于地图中心点, 1 screen point 对应的距离(单位是米)
 */
@property (nonatomic, readonly) double metersPerPointAtCurrentZoomLevel;

/**
 * @brief 在指定的缩放级别和指定纬度下, 1 screen point 对应的距离(单位是米).
 * @param latitude 指定纬度下
 * @param zoomLevel 指定的缩放级别
 * @return 对应的距离(单位是米)
 */
- (double)metersPerPointAtLatitude:(CLLocationDegrees)latitude zoomLevel:(CGFloat)zoomLevel;

#pragma mark - Gesture Control

/**
 * 设定地图View能否支持用户多点缩放, 默认为YES.
 */
@property(nonatomic, getter=isZoomEnabled) BOOL zoomEnabled;

/*!
 *  @brief  pinch时保持中心点, 默认为YES
 */
@property (nonatomic, assign, getter = isKeepCenterDuringZoom) BOOL keepCenterDuringZoom;

/**
 * 设定地图View能否支持用户移动地图, 默认为YES.
 */
@property(nonatomic, getter=isScrollEnabled) BOOL scrollEnabled;

/**
 * @brief  是否支持俯视. 默认为YES.
 */
@property (nonatomic, assign, getter=isOverlookingEnabled) BOOL overlookingEnabled;

/**
 * @brief  是否支持旋转. 默认为YES.
 */
@property (nonatomic, assign, getter=isRotateEnabled) BOOL rotateEnabled;

/**
 * @brief  当地图被单击时，是否总是触发 "地图点击回调"，默认为NO.
 *  地图点击回调:
 *  - (void)mapView:(QMapView *)mapView didTapAtCoordinate:(CLLocationCoordinate2D)coordinate;
 *
 *  当设置为NO时：只有当点击到地图空白处(即未点击到 Annotation, POI，Polyline，Polygon，定位标) 才会触发回调。
 *  当设置为YES时：只要点击到地图（未点击到 Annotation），就会触发回调。
 */
@property (nonatomic, assign) BOOL alwaysTriggerDidTapCoordinateEnabled;

#pragma mark - Coordinate Convert

/**
 * @brief  将经纬度坐标转换为View坐标
 * @param coordinate 待转换的经纬度坐标
 * @param view 指定相对的View
 * @return 转换后的View坐标
 */
- (CGPoint)convertCoordinate:(CLLocationCoordinate2D)coordinate toPointToView:(UIView *)view;

/**
 * @brief  将View坐标转换成经纬度坐标
 * @param point 待转换的View坐标
 * @param view point坐标所在的view
 * @return 转换后的经纬度坐标
 */
- (CLLocationCoordinate2D)convertPoint:(CGPoint)point toCoordinateFromView:(UIView *)view;

/**
 * @brief  将经纬度矩形区域转换为View矩形区域
 * @param region 待转换的经纬度矩形
 * @param view 指定相对的View
 * @return 转换后的View矩形区域
 */
- (CGRect)convertRegion:(QCoordinateRegion)region toRectToView:(UIView *)view;

/**
 * @brief  将View矩形区域转换成经纬度矩形区域
 * @param rect 待转换的View矩形区域
 * @param view rect坐标所在的view
 * @return 转换后的经纬度矩形区域
 */
- (QCoordinateRegion)convertRect:(CGRect)rect toRegionFromView:(UIView *)view;

@end

/**
 *  @brief  地图view的定位相关的API
 */
@interface QMapView (UserLocation)

/**
 *  @brief  地图view的定位标对象
 */
@property (nonatomic, readonly) QUserLocationPresentation *userLocatorPresentation;

/**
 * @brief 配置当前位置UI属性 (必须在QMapView 初始化以后, 定位开启之前调用)
 *
 * @param presentation 位置UI属性
 */
- (void)configureUserLocationPresentation:(QUserLocationPresentation *)presentation;

/**
 * @brief 开启定位并展示位置图标.
 */
@property (nonatomic, assign) BOOL showsUserLocation;

/**
 * @brief 当前位置信息
 */
@property (nonatomic, readonly) QUserLocation *userLocation;

/**
 * @brief 设定定位精度。默认为kCLLocationAccuracyBest
 */
@property (nonatomic) CLLocationAccuracy desiredAccuracy;

/**
 * @brief 设定定位的最小更新距离。默认为kCLDistanceFilterNone，会提示任何移动
 */
@property (nonatomic) CLLocationDistance distanceFilter;


/**
 * @brief 设定最小更新角度。默认为2度，设定为kCLHeadingFilterNone会提示任何角度改变
 */
@property (nonatomic) CLLocationDegrees headingFilter;

/**
 *  @brief 以上是否允许后台定位。ios9以上可用. 请参考CLLocationManager.allowsBackgroundLocationUpdates
 */
@property(assign, nonatomic) BOOL allowsBackgroundLocationUpdates;

/**
 *  指定定位是否会被系统自动暂停. 默认为YES.
 */
@property(assign, nonatomic) BOOL pausesLocationUpdatesAutomatically;

/**
 * @brief 定位精度权限状态
 */
@property(nonatomic, readonly) CLAccuracyAuthorization accuracyAuthorization API_AVAILABLE(ios(14));

/**
 * @brief 定位权限状态
 */
@property(nonatomic, readonly) CLAuthorizationStatus authorizationStatus API_AVAILABLE(ios(14));

/**
 *  @brief  定位用户位置的模式
 */
@property (nonatomic) QUserTrackingMode userTrackingMode;

/**
 *  @brief  设置追踪用户位置的模式
 *
 *  @param mode     要使用的模式
 *  @param animated 是否采用动画
 */
- (void)setUserTrackingMode:(QUserTrackingMode)mode animated:(BOOL)animated;

/**
 *  @brief  当前位置在地图中是否可见
 */
@property (nonatomic, readonly, getter=isUserLocationVisible) BOOL userLocationVisible;

/**
 *  @brief  在地图中隐藏位置图标
 */
- (void)setUserLocationHidden:(BOOL)hidden;

/**
 * @brief 展示/隐藏位置图标罗盘.
 */
- (void)setUserLocationCompassHidden:(BOOL)hidden;

/**
 * @brief 展示/隐藏位置图标红线.
 */
- (void)setUserLocationNavigationGravitylineHidden:(BOOL)hidden;

/**
 * @brief 申请临时精确定位权限
 * @param key info.plist中 NSLocationTemporaryUsageDescriptionDictionary 设置的 key
 */
- (void)requestTempPrecisedLocation:(QMapView *)mapView purposeKey:(NSString *)key completion:(void(^)(NSError * error))completion API_AVAILABLE(ios(14));

@end

/**
 *  @brief  地图view的点覆盖物相关的API
 */
@interface QMapView (Annotation)

/**
 * @brief  当前地图View的已经添加的标注数组
 */
@property(nonatomic, readonly) NSArray *annotations;

/**
 * @brief  当前选中的annotations
 *      get: 处于选中的标注数组，其count == 0 或者 1
 *      set: 数组中的第一个annotation会被选中 (index = 0)，其他则忽略. 若数组为空则取消当前选中的annotation.
 */
@property (nonatomic, copy) NSArray<id<QAnnotation>> *selectedAnnotations;

/**
 * @brief 获取指定投影矩形范围内的标注
 * @param mapRect 投影矩形范围，当mapRect 为空时(QMapRectIsEmpty) 会返回 nil.
 * @return 标注集合
 */
- (NSSet<id <QAnnotation>> *)annotationsInMapRect:(QMapRect)mapRect;

/**
 * @brief  向地图窗口添加标注，需要实现QMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 *
 * @param annotation 要添加的标注
 */
- (void)addAnnotation:(id <QAnnotation>)annotation;

/**
 * @brief  向地图窗口添加一组标注，需要实现QMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 * @param annotations 要添加的标注数组
 */
- (void)addAnnotations:(NSArray *)annotations;

/**
 * @brief  移除标注
 * @param annotation 要移除的标注
 */
- (void)removeAnnotation:(id <QAnnotation>)annotation;

/**
 * @brief  移除一组标注
 * @param annotations 要移除的标注数组
 */
- (void)removeAnnotations:(NSArray *)annotations;

/**
 * @brief  查找指定标注对应的View，如果该标注尚未显示，返回nil
 * @param annotation 指定的标注
 * @return 指定标注对应的View
 */
- (QAnnotationView *)viewForAnnotation:(id <QAnnotation>)annotation;

/**
 * @brief  根据指定标识查找一个可被复用的标注View，一般在delegate中使用，用此函数来代替新申请一个View
 * @param identifier 指定标识
 * @return 返回可被复用的标注View
 */
- (QAnnotationView *)dequeueReusableAnnotationViewWithIdentifier:(NSString *)identifier;

/**
 * @brief  将制定的annotation放在最上层渲染.
 *  @param annotation 指定的annotation
 *
 * @note Deprecated 请使用QAnnotationView.zIndex管理顺序（默认会将本annotationView.zIndex设置为当前顶部的zIndex+1）
 */
- (void)bringAnnotationToFront:(id <QAnnotation>)annotation DEPRECATED_ATTRIBUTE;

/**
 * @brief  选中指定的标注
 * @param annotation 指定的标注
 * @param animated 是否支持动画
 */
- (void)selectAnnotation:(id <QAnnotation>)annotation animated:(BOOL)animated;

/**
 * @brief  取消指定的标注的选中状态
 * @param annotation 指定的标注
 * @param animated 是否支持动画
 */
- (void)deselectAnnotation:(id <QAnnotation>)annotation animated:(BOOL)animated;

/**
 * @brief 设置地图使其可以显示数组中所有的annotation, 当只有一个时，则将其作为地图的中心点.
 * @param annotations    需要显示的annotations
 * @param insets      insets 嵌入边界
 * @param animated    是否执行动画
 */
- (void)showAnnotations:(NSArray<id<QAnnotation>> *)annotations edgePadding:(UIEdgeInsets)insets animated:(BOOL)animated;

@end


#pragma mark - Overlay

/**
 *  @brief  地图view的线面覆盖物相关的API
 */
@interface QMapView (Overlay)

/**
 * @brief  当前mapView中已经添加的Overlay数组
 */
@property (nonatomic, readonly) NSArray *overlays;

/**
 * @brief  向地图窗口添加Overlay，需要实现QMapViewDelegate的-mapView:viewForOverlay:函数来生成标注对应的View
 * @param overlay 要添加的overlay
 */
- (void)addOverlay:(id <QOverlay>)overlay;

/**
 * @brief  批量向地图窗口添加Overlay，需要实现QMapViewDelegate的-mapView:viewForOverlay:函数来生成标注对应的View
 * @param overlays 要添加的overlay列表
 */
- (void)addOverlays:(NSArray<id <QOverlay>> *)overlays;

/**
 * @brief  移除Overlay
 * @param overlay 要移除的overlay
 */
- (void)removeOverlay:(id <QOverlay>)overlay;

/**
 * @brief  移除Overlay
 * @param overlays 要移除的overlay列表
 */
- (void)removeOverlays:(NSArray<id <QOverlay>> *)overlays;

/**
 * @brief  返回指定overlay对象的OverlayView
 * @param overlay 待查询的overlay
 * @return 对应的OverlayView
 */
- (QOverlayView *)viewForOverlay:(id <QOverlay>)overlay;

/**
 * @brief 设置地图使其可以显示数组中所有的overlay,
 * @param overlays    需要显示的overlays
 * @param insets      insets 嵌入边界
 * @param animated    是否执行动画
 */
- (void)showOverlays:(NSArray<id<QOverlay>> *)overlays edgePadding:(UIEdgeInsets)insets animated:(BOOL)animated;

@end


#pragma mark - CustomLayer

/**
 *  @brief  个性化图层相关的API
 */
@interface QMapView (CustomLayer)

/**
 * @brief  向地图添加一个图层
 * @param layer 要添加的图层
 */
- (void)addCustomLayer:(QCustomLayer *)layer;

/**
 * @brief  从地图移除一个个性化图层
 * @param layer 要移除的图层
 */
- (void)removeCustomLayer:(QCustomLayer *)layer;

@end

#pragma mark - POILayer

@interface QMapView (AOILayer)

/**
 * @brief 向地图添加一个 AOI 图层
 * @param layer 需要添加的图层
 *        回调中返回添加图层的状态: 成功或失败
 */

- (void)addAOILayer:(QAOILayer *)layer callback:(void(^)(BOOL success))callback;

/**
 * @brief  从地图移除一个 AOI 图层
 * @param layer 要移除的图层
 */
- (void)removeAOILayer:(QAOILayer *)layer;

@end

#pragma mark - Snapshot
/**
 * @brief  截图相关API
 */
@interface QMapView (Snapshot)

/**
 *  @brief  截图
 *
 *  @return 截图image
 */
- (UIImage *)takeSnapshot __attribute__ ((deprecated("use - (void)takeSnapshotInRect:(CGRect)rect completion:(void (^)(UIImage *resultImage))completion instead")));

/**
 *  @brief  异步截图 (默认超时时间为2.5秒)
 *
 *  @param rect 范围
 *  @param completion 异步block结果
 */
- (void)takeSnapshotInRect:(CGRect)rect completion:(void (^)(UIImage *resultImage))completion;

/**
 *  @brief  异步截图
 *
 *  @param rect 范围
 *  @param timeout 超时时间.
 *  @param completion 异步block结果
 */
- (void)takeSnapshotInRect:(CGRect)rect timeout:(CFTimeInterval)timeout completion:(void (^)(UIImage *resultImage))completion;

/**
 *  @brief  异步截图
 *
 *  @param rect 范围
 *  @param timeout 超时时间.
 *  @param afterUpdates 是否等待当前内容更新完.
 *  @param completion 异步block结果
 */
- (void)takeSnapshotInRect:(CGRect)rect timeout:(CFTimeInterval)timeout afterScreenUpdates:(BOOL)afterUpdates completion:(void (^)(UIImage *resultImage))completion;

@end

#pragma mark - QPoiInfo

/**
 * @brief 点击底图上文字图标的数据信息
 */
@interface QPoiInfo : NSObject

/**
 * @brief 唯一标识(可能为空).
 */
@property (nonatomic, copy) NSString *uid;

/**
 * @brief 名字信息
 */
@property (nonatomic, copy) NSString *name;

/**
 * @brief 经纬坐标
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

@end

/**
 * @brief 点击室内图上文字图标的数据信息
 */
@interface QIndoorPoiInfo : QPoiInfo

/**
 * @brief 所在室内图楼层
 */
@property (nonatomic, copy) NSString *levelName;

/**
 * @brief 所在室内图唯一标识
 */
@property (nonatomic, copy) NSString *buildingGUID;

/**
 * @brief 所在室内图楼的名称
 */
@property (nonatomic, copy) NSString *buildingName;

@end

/**
 * @brief 点击点事件图标的数据信息
 *        可通过 discription 获取快捷点事件简介
 */
@interface QPointEventInfo : QPoiInfo

/**
 * @brief 事件来源
 */
@property (nonatomic, copy) NSString *source;

/**
 * @brief 事件类型
 */
@property (nonatomic, copy) NSString *eventName;

/**
 * @brief 事件发生道路
 */
@property (nonatomic, copy) NSString *road;

/**
 * @brief 事件详情信息
 */
@property (nonatomic, copy) NSString *detail;

/**
 * @brief 事件开始时间
 */
@property (nonatomic, assign) NSTimeInterval startTime;

/**
 * @brief 事件结束时间
 */
@property (nonatomic, assign) NSTimeInterval endTime;

/**
 * @brief 事件更新时间
 */
@property (nonatomic, assign) NSTimeInterval updateTime;

@end

/**
 * @brief 点击AOI面子点图标的数据信息
 *        uid 为子点的唯一标识
 */

@interface QSubPoiInfo : QPoiInfo

/**
 * @brief 子点的主点唯一标识
 */
@property (nonatomic, copy) NSString *parentID;

@end

/**
 *  @brief  地图view的错误信息, 用于定位问题
 */
@interface QMapView (Debug)

/**
 *  @brief  地图view的错误信息, 用于定位问题
 */
- (NSString *)getDebugError;

@end

@interface QMapView (Cache)

/**
 *  @brief  清理地图缓存数据。注: 此接口必须在地图初始化前调用
 */
+ (void)clearMapCache;

@end

#pragma mark - QMapViewDelegate

/**
 * @brief QMapViewDelegate:MapView的Delegate,mapView通过此类来通知用户对应的事件
 **/
@protocol QMapViewDelegate <NSObject>

@optional

/**
*  @brief  地图鉴权成功会调用此接口
*
*  @param mapView  地图view
*/
- (void)mapViewAuthenticationDidComplete:(QMapView *)mapView;

/**
*  @brief  地图鉴权失败后会调用此接口.
*
*  @param mapView  地图view
*  @param error  鉴权失败错误信息.
*            NSURLErrorDomain : 网络链路error问题
*            QMapAuthenticationErrorDomain: 鉴权服务error 问题.
*/
- (void)mapViewAuthentication:(QMapView *)mapView didFailWithError:(NSError *)error;

/**
*  @brief  地图初始化完成并且配置文件加载完成后会调用此接口
*
*  @param mapView  地图view
*/
- (void)mapViewInitComplete:(QMapView *)mapView;

/**
 *  @brief  地图加载完成后会调用此接口
 *
 *  @param mapView  地图view
 */
- (void)mapViewFirstRenderDidComplete:(QMapView *)mapView;

/**
 *  @brief  地图数据加载失败时会调用此接口
 *
 *  @param mapView  地图view
 *  @param error 错误信息
 */
- (void)mapViewDidFailLoadingMap:(QMapView *)mapView withError:(NSError *)error;

/**
 * @brief  地图区域即将改变时会调用此接口
 * @param mapView 地图View
 * @param animated 是否动画
 * @param bGesture 是否由手势触发
 */
- (void)mapView:(QMapView *)mapView regionWillChangeAnimated:(BOOL)animated gesture:(BOOL)bGesture;

/**
 * @brief  地图区域改变时会调用此接口. 视野持续变化时本回调可能会被频繁多次调用, 请不要做耗时或复杂的事情
 * @param mapView 地图View
 */
- (void)mapViewRegionChange:(QMapView *)mapView;

/**
 * @brief  地图区域改变完成后会调用此接口,如果是由手势触发，当触摸结束且地图region改变的动画结束后才会触发此回调
 * @param mapView 地图View
 * @param animated 是否动画
 * @param bGesture region变化是否由手势触发
 */
- (void)mapView:(QMapView *)mapView regionDidChangeAnimated:(BOOL)animated gesture:(BOOL)bGesture;

/**
 * @brief  地图将要发生中心点移动时调用此回调.
 * @param mapView 地图View
 * @param animated 是否动画
 * @param bGesture 是否由手势触发
 */
- (void)mapView:(QMapView *)mapView willMoveAnimated:(BOOL)animated gesture:(BOOL)bGesture;

/**
 * @brief  地图中心点移动结束后，调用此回调.
 * @param mapView 地图View
 * @param animated 是否动画
 * @param bGesture 是否由手势触发
 */
- (void)mapView:(QMapView *)mapView didMoveAnimated:(BOOL)animated gesture:(BOOL)bGesture;

/**
 * @brief  地图的zoomLevel级别将要发生变化时，调用此回调.
 * @param mapView 地图View
 * @param animated 是否动画
 * @param bGesture 是否由手势触发
 */
- (void)mapView:(QMapView *)mapView willZoomAnimated:(BOOL)animated gesture:(BOOL)bGesture;

/**
 * @brief  地图zoomLevel级别变化结束后，调用此回调.
 * @param mapView 地图View
 * @param animated 是否动画
 * @param bGesture 是否由手势触发
 */
- (void)mapView:(QMapView *)mapView didZoomAnimated:(BOOL)animated gesture:(BOOL)bGesture;

/**
 *  @brief  地图比例尺变化时调用此接口
 *
 *  @param mapView  地图view
 *  @param unitLength 当前比例尺的单位长度, 单位:米。
 */
- (void)mapView:(QMapView *)mapView scaleViewChanged:(CGFloat)unitLength;

/**
 * @brief  地图内置手势触发时会触发此回调.
 * @param mapView 地图View
 * @param gestureType 手势类型
 */
- (void)mapView:(QMapView *)mapView gestureDidTrigger:(QGestureType)gestureType;

/**
 * @brief  地图内置手势结束时会触发此回调
 * @param mapView 地图View
 * @param gestureType 手势类型
 *
 * @notes 部分手势有此回调
 */
- (void)mapView:(QMapView *)mapView gestureDidEnd:(QGestureType)gestureType;

/**
 * @brief 地图渲染每一帧过程中都会调用此接口
 * @param mapView 地图View
 */
- (void)mapViewDrawFrame:(QMapView *)mapView;

/**
 * @brief  点击地图空白处会调用此接口.
 * @param mapView 地图View
 * @param coordinate 坐标
 */
- (void)mapView:(QMapView *)mapView didTapAtCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 * @brief  点击地图poi图标处会调用此接口.
 * @param mapView 地图View
 * @param poi poi数据
 */
- (void)mapView:(QMapView *)mapView didTapPoi:(QPoiInfo *)poi;

/**
 * @brief  点击地图上添加的overlay覆盖物会调用此接口.
 * @param mapView 地图View
 * @param overlay overlay对象. 暂时只支持线(QPolyline及子类)的点击
 */
- (void)mapView:(QMapView *)mapView didTapOverlay:(id<QOverlay>)overlay __attribute__ ((deprecated("use - (void)mapView:(QMapView *)mapView didTapOverlay:(id<QOverlay>)overlay coordinate:(CLLocationCoordinate2D)coordinate instead")));

/**
 * @brief  点击地图上添加的overlay覆盖物会调用此接口.
 * @note - (void)mapView:(QMapView *)mapView didTapOverlay:(id<QOverlay>)overlay 该废弃接口同样会触发.
 *
 * @param mapView 地图View
 * @param overlay overlay对象. 暂时只支持线(QPolyline及子类)的点击
 * @param coordinate 点击到地图上的经纬度坐标.
 */
- (void)mapView:(QMapView *)mapView didTapOverlay:(id<QOverlay>)overlay coordinate:(CLLocationCoordinate2D)coordinate;

/**
 * @brief 点击地图上的定位标会调用次接口
 * @param mapView 地图View
 * @param location 返回定位标的经纬度
 */
- (void)mapView:(QMapView *)mapView didTapMyLocation:(CLLocationCoordinate2D)location;

/**
 * @brief 根据anntation生成对应的View
 * @param mapView 地图View
 * @param annotation 指定的标注
 * @return 生成的标注View
 */
- (QAnnotationView *)mapView:(QMapView *)mapView viewForAnnotation:(id <QAnnotation>)annotation;

/**
 * @brief 根据anntationView生成对应的CustomCallout (当标注被选中后会调用)
 * @param mapView 地图View
 * @param annotationView 指定的标注view
 * @return 对应的CustomCallout
 */
- (UIView *)mapView:(QMapView *)mapView customCalloutForAnnotationView:(QAnnotationView *)annotationView;

/**
 * @brief  当mapView新添加annotation views时，调用此接口
 * @param mapView 地图View
 * @param views 新添加的annotation views
 */
- (void)mapView:(QMapView *)mapView didAddAnnotationViews:(NSArray<QAnnotationView *> *)views;

/**
 * @brief  当选中一个annotation view时，调用此接口
 * @param mapView 地图View
 * @param view 选中的annotation view
 */
- (void)mapView:(QMapView *)mapView didSelectAnnotationView:(QAnnotationView *)view;

/**
 * @brief 当annotation view时被手势单击后，调用此接口
 * @param mapView 地图View
 * @param view 被单击的annotation view
 */
- (void)mapView:(QMapView *)mapView didAnnotationViewTapped:(QAnnotationView *)view;

/**
 * @brief  当取消选中一个annotation view时，调用此接口
 * @param mapView 地图View
 * @param view 取消选中的annotation view
 */
- (void)mapView:(QMapView *)mapView didDeselectAnnotationView:(QAnnotationView *)view;

/**
 *  @brief  拖动annotationView时view的状态变化
 *
 *  @param mapView  地图view
 *  @param view     目标annotationView
 *  @param newState 新状态
 *  @param oldState 旧状态
 */
- (void)mapView:(QMapView *)mapView annotationView:(QAnnotationView *)view didChangeDragState:(QAnnotationViewDragState)newState
   fromOldState:(QAnnotationViewDragState)oldState;

/**
 *  @brief  标注view的accessory view(必须继承自UIControl)被点击时，触发该回调
 *
 *  @param mapView 地图view
 *  @param view    callout所属的标注view
 *  @param control 对应control
 */
- (void)mapView:(QMapView *)mapView annotationView:(QAnnotationView *)view calloutAccessoryControlTapped:(UIControl *)control;

/**
* @brief  当选中一个 callout view时，调用此接口
* @param mapView 地图View
* @param view 选中的 callout view 对应的 annotation view
*/
- (void)mapView:(QMapView *)mapView annotationViewCalloutTapped:(QAnnotationView *)view;

/**
 * @brief  根据overlay生成对应的View
 * @param mapView 地图View
 * @param overlay 指定的overlay
 * @return 生成的覆盖物View
 */
- (QOverlayView *)mapView:(QMapView *)mapView viewForOverlay:(id <QOverlay>)overlay;

/**
 * @brief  当mapView新添加overlay views时，调用此接口
 * @param mapView 地图View
 * @param overlayViews 新添加的overlay views
 */
- (void)mapView:(QMapView *)mapView didAddOverlayViews:(NSArray *)overlayViews;

/**
 * @brief  在地图View将要启动定位时，会调用此函数
 * @param mapView 地图View
 */
- (void)mapViewWillStartLocatingUser:(QMapView *)mapView;

/**
 * @brief  在地图View停止定位后，会调用此函数
 * @param mapView 地图View
 */
- (void)mapViewDidStopLocatingUser:(QMapView *)mapView;

/**
 * @brief 用户位置更新后，会调用此函数
 * @param mapView 地图View
 * @param userLocation 新的用户位置
 * @param fromHeading 是否为heading 变化触发，如果为location变化触发,则为NO
 */
- (void)mapView:(QMapView *)mapView didUpdateUserLocation:(QUserLocation *)userLocation fromHeading:(BOOL)fromHeading;
/**
 * @brief  定位失败后，会调用此函数
 * @param mapView 地图View
 * @param error 错误号，参考CLError.h中定义的错误号
 */
- (void)mapView:(QMapView *)mapView didFailToLocateUserWithError:(NSError *)error;

/**
 * @brief 定位时的userTrackingMode 改变时delegate调用此函数
 *  @param mapView 地图View
 *  @param mode QMUserTrackingMode
 *  @param animated 是否有动画
 */
- (void)mapView:(QMapView *)mapView didChangeUserTrackingMode:(QUserTrackingMode)mode animated:(BOOL)animated;

/**
 * @brief 用户定位权限变更时会调用此接口
 * @param mapView 	地图View
 */
- (void)locationManagerDidChangeAuthorization:(QMapView *)mapView;

@end
