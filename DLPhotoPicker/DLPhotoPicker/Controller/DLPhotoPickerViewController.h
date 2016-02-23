//
//  DLPhotoPickerViewController.h
//  DLPhotoPicker
//
//  Created by 沧海无际 on 16/2/20.
//  Copyright © 2016年 darling0825. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DLPhotoCollection;
@class DLPhotoAsset;
@protocol DLPhotoPickerViewControllerDelegate;

@interface DLPhotoPickerViewController : UIViewController

/**
 *  The assets picker’s delegate object.
 */
@property (nonatomic, weak) id<DLPhotoPickerViewControllerDelegate> delegate;

/**
 The navigation title used by the DLPhotoPickerViewController.
 */
@property (copy, nonatomic) NSString *navigationTitle;

/**
 *  Determines whether or not the number of assets is shown in the album list.
 *
 *  The number of assets is visible by default. To hide the number of assets, (e.g. implementing `shouldShowAsset` delegate method)
 *  set this property’s value to `NO`.
 */
@property (nonatomic, assign) BOOL showsNumberOfAssets;

@end

@protocol DLPhotoPickerViewControllerDelegate <NSObject>


/**
 *  @name Closing the Picker
 */

/**
 *  Tells the delegate that the user finish picking photos or videos.
 *
 *  @param picker The controller object managing the assets picker interface.
 *  @param assets An array containing picked `DLPhotoAsset` objects.
 *
 *  @see pickerControllerDidCancel:
 */
- (void)pickerController:(DLPhotoPickerViewController *)picker didFinishPickingAssets:(NSArray *)assets;

@optional

/**
 *  Tells the delegate that the user cancelled the pick operation.
 *
 *  @param picker The controller object managing the assets picker interface.
 *
 *  @see pickerController:didFinishPickingAssets:
 */
- (void)pickerControllerDidCancel:(DLPhotoPickerViewController *)picker;


/**
 *  @name Configuting Asset Selection View
 */

/**
 *  Ask the delegate the layout of asset selection view (UICollectionView).
 *
 *  @param picker The controller object managing the assets picker interface.
 *  @param contentSize  The bounds size of current view.
 *  @param trait The trait collection of current view.
 *
 *  @return Custom `UICollectionViewLayout` for the asset selection view.
 */
- (UICollectionViewLayout *)pickerController:(DLPhotoPickerViewController *)picker collectionViewLayoutForContentSize:(CGSize)contentSize traitCollection:(UITraitCollection *)trait;


/**
 *  Ask the delegate if the asset selection view should sroll to bottom on shown.
 *
 *  @param picker The controller object managing the assets picker interface.
 *  @param assetCollection  The asset collection of asset selection view.
 *
 *  @return `YES` (the default) if the asset grid should scroll to bottom on shown or `NO` if it should not.
 */

- (BOOL)pickerController:(DLPhotoPickerViewController *)picker shouldScrollToBottomForPhotoCollection:(DLPhotoCollection *)assetCollection;


/**
 *  @name Enabling Assets
 */

/**
 *  Ask the delegate if the specified asset should be enabled for selection.
 *
 *  @param picker The controller object managing the assets picker interface.
 *  @param asset  The asset to be enabled.
 *
 *  @return `YES` if the asset should be enabled or `NO` if it should not.
 *
 *  @see pickerController:shouldShowAsset:
 */
- (BOOL)pickerController:(DLPhotoPickerViewController *)picker shouldEnableAsset:(DLPhotoAsset *)asset;


/**
 *  @name Managing the Selected Assets
 */

/**
 *  Asks the delegate if the specified asset should be selected.
 *
 *  @param picker The controller object managing the assets picker interface.
 *  @param asset  The asset to be selected.
 *
 *  @return `YES` if the asset should be selected or `NO` if it should not.
 *
 *  @see pickerController:shouldDeselectAsset:
 */
- (BOOL)pickerController:(DLPhotoPickerViewController *)picker shouldSelectAsset:(DLPhotoAsset *)asset;

/**
 *  Tells the delegate that the asset was selected.
 *
 *  @param picker The controller object managing the assets picker interface.
 *  @param asset  The asset that was selected.
 *
 *  @see pickerController:didDeselectAsset:
 */
- (void)pickerController:(DLPhotoPickerViewController *)picker didSelectAsset:(DLPhotoAsset *)asset;

/**
 *  Asks the delegate if the specified asset should be deselected.
 *
 *  @param picker The controller object managing the assets picker interface.
 *  @param asset  The asset to be deselected.
 *
 *  @return `YES` if the asset should be deselected or `NO` if it should not.
 *
 *  @see pickerController:shouldSelectAsset:
 */
- (BOOL)pickerController:(DLPhotoPickerViewController *)picker shouldDeselectAsset:(DLPhotoAsset *)asset;

/**
 *  Tells the delegate that the item at the specified path was deselected.
 *
 *  @param picker The controller object managing the assets picker interface.
 *  @param asset  The asset that was deselected.
 *
 *  @see pickerController:didSelectAsset:
 */
- (void)pickerController:(DLPhotoPickerViewController *)picker didDeselectAsset:(DLPhotoAsset *)asset;



/**
 *  @name Managing Asset Highlighting
 */

/**
 *  Asks the delegate if the specified asset should be highlighted.
 *
 *  @param picker The controller object managing the assets picker interface.
 *  @param asset  The asset to be highlighted.
 *
 *  @return `YES` if the asset should be highlighted or `NO` if it should not.
 */
- (BOOL)pickerController:(DLPhotoPickerViewController *)picker shouldHighlightAsset:(DLPhotoAsset *)asset;

/**
 *  Tells the delegate that asset was highlighted.
 *
 *  @param picker The controller object managing the assets picker interface.
 *  @param asset  The asset that was highlighted.
 *
 *  @see pickerController:didUnhighlightAsset:
 */
- (void)pickerController:(DLPhotoPickerViewController *)picker didHighlightAsset:(DLPhotoAsset *)asset;


/**
 *  Tells the delegate that the highlight was removed from the asset.
 *
 *  @param picker The controller object managing the assets picker interface.
 *  @param asset  The asset that had its highlight removed.
 *
 *  @see pickerController:didHighlightAsset:
 */
- (void)pickerController:(DLPhotoPickerViewController *)picker didUnhighlightAsset:(DLPhotoAsset *)asset;




/**
 *  @name Notifications
 */

/**
 *  Sent when the assets selected or deselected
 *
 *  The notification’s `object` is an `NSArray` object of selected assets
 */
extern NSString * const DLPhotoPickerViewSelectedAssetsDidChangeNotification;

/**
 *  Sent when asset is selected
 *
 *  The notification’s `object` is a `DLPhotoAsset` that is selected
 */
extern NSString * const DLPhotoPickerViewDidSelectAssetNotification;

/**
 *  Sent when asset is deselected
 *
 *  The notification’s `object` is a `DLPhotoAsset` that is deselected
 */
extern NSString * const DLPhotoPickerViewDidDeselectAssetNotification;


@end
