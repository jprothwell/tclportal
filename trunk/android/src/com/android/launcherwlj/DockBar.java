package com.android.launcherwlj;

import java.net.URISyntaxException;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.SQLException;
import android.graphics.Bitmap;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.Toast;

import com.android.launcherwlj.R;
import com.android.launcherwlj.DragController.DragListener;

public class DockBar extends LinearLayout implements DropTarget, DragSource,
		DragController.DragListener, View.OnLongClickListener {

	private Launcher mLauncher;
	private DragController mDragController;
	private Workspace mWorkspace;
	private View mDragView;
	private LinearLayout mItemHolder;
	private View mScrollView;
	private View mSelectedView;
	private Context mContext;
	private int height = 0;
	private int width = 0;

	public DockBar(Context context) {
		super(context);
		// TODO Auto-generated constructor stub
		mContext = context;
		DisplayMetrics dm = new DisplayMetrics();
		((Activity) mContext).getWindowManager().getDefaultDisplay()
				.getMetrics(dm);
		height = dm.heightPixels;
		width = dm.widthPixels;
	}

	public DockBar(Context context, AttributeSet attrs) {
		super(context, attrs);
		mContext = context;
		DisplayMetrics dm = new DisplayMetrics();
		((Activity) mContext).getWindowManager().getDefaultDisplay()
				.getMetrics(dm);
		height = dm.heightPixels;
		width = dm.widthPixels;
	}

	@Override
	protected void onFinishInflate() {
		// TODO Auto-generated method stub
		Log.i("hmg", "DockBar->onFinishInflate");
		mItemHolder = (LinearLayout) findViewById(R.id.dock_item_holder);
		mScrollView = findViewById(R.id.dock_scroll_view);
		// 恢复状态信息
//		ShortcutInfo info = null;
//		DockListProvider docklist = new DockListProvider(mContext);
//		docklist.open();
//		Cursor dockcur = docklist.getAllTitles();
//		if (dockcur.moveToFirst()) {
//			do {
//				String title = dockcur.getString(1);
//				String in = dockcur.getString(2);
//				int position = dockcur.getInt(3);
//				Log.d("xx","huifu position="+position);
//				Intent intent;
//				try {
//					intent = Intent.parseUri(in, 0);
//					Log.d("xx","huifu intent="+intent);
//					Cursor cursor = getShortcutInfo(mContext, title, intent);
//					if (cursor != null) {
//						final int titleIndex = cursor
//								.getColumnIndexOrThrow(LauncherSettings.Favorites.TITLE);
//						final int iconIndex = cursor
//								.getColumnIndexOrThrow(LauncherSettings.Favorites.ICON);
//						info = mLauncher.mModel.getShortcutInfo(mContext
//								.getPackageManager(), intent, mContext, cursor,
//								iconIndex, titleIndex);
//						addItemAt(null,(ItemInfo)info,position);
//					}
//					cursor.close();
//				} catch (URISyntaxException e) {
//					// TODO Auto-generated catch block
//					e.printStackTrace();
//				}
//			} while (dockcur.moveToNext());
//		}
//		dockcur.close();
//		docklist.close();
		super.onFinishInflate();
	}

	@Override
	protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
		// TODO Auto-generated method stub
		super.onMeasure(widthMeasureSpec, heightMeasureSpec);
		// 居中显示
		FrameLayout.LayoutParams lp = (FrameLayout.LayoutParams) mItemHolder
				.getLayoutParams();
		lp.gravity = Gravity.CENTER;
		mItemHolder.setLayoutParams(lp);
		postInvalidate();
		requestLayout();
	}

	@Override
	public boolean acceptDrop(DragSource source, int x, int y, int xOffset,
			int yOffset, DragView dragView, Object dragInfo) {
		// 接受什么类型的图标
		Log.i("hmg", "DockBar->acceptDrop");
		ShortcutInfo shortcutInfo = null;
		final ItemInfo item = (ItemInfo) dragInfo;
		if (item.itemType == LauncherSettings.Favorites.ITEM_TYPE_APPWIDGET
				|| item.itemType == LauncherSettings.Favorites.ITEM_TYPE_LIVE_FOLDER
				|| item.itemType == LauncherSettings.Favorites.ITEM_TYPE_USER_FOLDER
				|| item.itemType == LauncherSettings.Favorites.ITEM_TYPE_WIDGET_PHOTO_FRAME
				|| item.itemType == LauncherSettings.Favorites.ITEM_TYPE_WIDGET_SEARCH
				|| item.itemType == LauncherSettings.Favorites.ITEM_TYPE_WIDGET_CLOCK) {
			return false;
		}
		// 如果对象的快捷方式已经存在则不添加
		if (item.container == NO_ID && item instanceof ApplicationInfo) {
			shortcutInfo = new ShortcutInfo((ApplicationInfo) item);
		} else
			shortcutInfo = (ShortcutInfo) item;

		if (ShutcutIsAdded(shortcutInfo)) {
			Toast
					.makeText(mContext, R.string.shutcutisadded,
							Toast.LENGTH_LONG).show();
			return false;
		}
		return true;
	}

	@Override
	public Rect estimateDropLocation(DragSource source, int x, int y,
			int xOffset, int yOffset, DragView dragView, Object dragInfo,
			Rect recycle) {
		// TODO Auto-generated method stub
		Log.i("hmg", "DockBar->estimateDropLocation");
		return null;
	}

	@Override
	public void onDragEnter(DragSource source, int x, int y, int xOffset,
			int yOffset, DragView dragView, Object dragInfo) {
		// TODO Auto-generated method stub
		Log.i("hmg", "DockBar->onDragEnter");

	}

	@Override
	public void onDragExit(DragSource source, int x, int y, int xOffset,
			int yOffset, DragView dragView, Object dragInfo) {
		// TODO Auto-generated method stub
		mItemHolder.removeView(mDragView);
		Log.i("hmg", "DockBar->onDragExit");
	}

	@Override
	public void onDragOver(DragSource source, int x, int y, int xOffset,
			int yOffset, DragView dragView, Object dragInfo) {
		// TODO Auto-generated method stub
		Log.i("hmg", "DockBar->onDragOver");
	}

	private void addItemAt(DragSource source, ItemInfo itemInfo, int position) {
		View view = null;
		ShortcutInfo shortcutInfo = null;
		switch (itemInfo.itemType) {
		case LauncherSettings.Favorites.ITEM_TYPE_APPLICATION:
		case LauncherSettings.Favorites.ITEM_TYPE_SHORTCUT:

			// 拖拽图标来自于app list
			if (itemInfo.container == NO_ID
					&& itemInfo instanceof ApplicationInfo) {
				// 与来自桌面的图标包含信息不一样，具体看源码
				shortcutInfo = new ShortcutInfo((ApplicationInfo) itemInfo);
			} else
				shortcutInfo = (ShortcutInfo) itemInfo; // 拖拽图标来自桌面
			// 调用Launcher中的createSmallShortcut生成一个imageView
			view = mLauncher.CreateDockShortcut(shortcutInfo);
			view.setOnLongClickListener(this);
			break;
		case LauncherSettings.Favorites.ITEM_TYPE_USER_FOLDER:
			break;
		default:
			throw new IllegalStateException("Unknown item type: "
					+ itemInfo.itemType);
		}
		Log.d("xx", "position=" + position);
		switch (position) {
		case 0:
			mItemHolder.removeViewAt(position);
			if (height > width)
				view.setBackgroundResource(R.drawable.hotseat_bg_left);
			else
				view.setBackgroundResource(R.drawable.hotseat_bg_right);
			mItemHolder.addView(view, position);
			break;
		case 1:
			mItemHolder.removeViewAt(position);
			view.setBackgroundResource(R.drawable.hotseat_bg_center);
			mItemHolder.addView(view, position);
			break;
		case 2:
			DeleteZone(source, itemInfo);
			break;
		case 3:
			mItemHolder.removeViewAt(position);
			view.setBackgroundResource(R.drawable.hotseat_bg_center);
			mItemHolder.addView(view, position);
			break;
		case 4:
			mItemHolder.removeViewAt(position);
			if (height > width)
				view.setBackgroundResource(R.drawable.hotseat_bg_right);
			else
				view.setBackgroundResource(R.drawable.hotseat_bg_left);
			mItemHolder.addView(view, position);
			break;
		default:
			break;
		}
		//保存状态
//		if(position!=2)
//		saveOneDockIcon((ShortcutInfo)itemInfo,position);
	}

	/*
	 * 传入x坐标，判断新图标的位置，此处仅判断竖屏
	 */
	public int getLocation(int x, int y) {

		Log.d("xx", "getChildCount=" + mItemHolder.getChildCount());
		for (int i = 0; i < mItemHolder.getChildCount(); i++) {
			View iv = mItemHolder.getChildAt(i);

			int[] position = new int[2];
			// 获取坐标，如果要适应横屏可以稍作修改，比较Y值
			iv.getLocationOnScreen(position);
			// 判断释放时新增的图标在原图标的之前还是之后
			if (height > width) {
				if (x <= (position[0] + (iv.getWidth()))) {
					Log.d("xx", "i=" + i);
					if (i < 2)
						return i;
					else if (i > 2 && i < mItemHolder.getChildCount())
						return i;
				}
			} else {
				if (y <= (position[1] + (iv.getHeight()))) {
					Log.d("xx", "i=" + i);
					if (i < 2)
						return i;
					else if (i > 2 && i < mItemHolder.getChildCount())
						return i;
				}
			}
		}
		return mItemHolder.getChildCount() - 1;
	}

	public int getOutLocation(View curview) {
		Log.d("xx", "getOutLocation getChildCount="
				+ mItemHolder.getChildCount());
		for (int i = 0; i < mItemHolder.getChildCount(); i++) {
			View iv = mItemHolder.getChildAt(i);
			if (curview == iv)
				return i;

		}
		return mItemHolder.getChildCount();
	}

	/*
	 * 拖拽释放时响应
	 */
	@Override
	public void onDrop(DragSource source, int x, int y, int xOffset,
			int yOffset, DragView dragView, Object dragInfo) {
		Log.i("hmg", "DockBar->onDrop");
		int position = 0;
		position = getLocation(x, y); // 根据释放时的坐标，获取插入位置
		addItemAt(source, (ItemInfo) dragInfo, position);
	}

	@Override
	public void onDropCompleted(View target, boolean success) {
		// TODO Auto-generated method stub
		Log.i("hmg", "DockBar->onDropCompleted");

	}

	@Override
	public void setDragController(DragController dragController) {
		// TODO Auto-generated method stub
		mDragController = dragController;
	}

	@Override
	public void onDragEnd() {
		// TODO Auto-generated method stub
		Log.i("hmg", "DockBar->onDragEnd");
	}

	@Override
	public void onDragStart(DragSource source, Object dragInfo, int dragAction) {
		// TODO Auto-generated method stub
		Log.i("hmg", "DockBar->onDragStart");
	}

	void setLauncher(Launcher launcher) {
		mLauncher = launcher;
	}

	void setWorkspace(Workspace workspace) {
		mWorkspace = workspace;
	}

	@Override
	public boolean onLongClick(View v) {
		// TODO Auto-generated method stub
		Log.i("hmg", "DockBar->onLongClick");
		if (mLauncher.isAllAppsVisible())
			mLauncher.closeAllApps(false);
		mSelectedView = v;
		mSelectedView.setBackgroundDrawable(null);
		mDragController.startDrag(v, this, v.getTag(),
				DragController.DRAG_ACTION_MOVE);
		removeSelectedItem();
		return true;
	}

	private void removeSelectedItem() {
		if (mSelectedView == null)
			return;
		int position = getOutLocation(mSelectedView);
		Log.d("xx", "getOutLocation=" + position);
		int child_width = mSelectedView.getWidth();
		int child_height = mSelectedView.getHeight();
		LinearLayout.LayoutParams lp;
		ImageView child = null;
		lp = new LinearLayout.LayoutParams(child_width, child_height);
		if (position == 0) {
			child = new ImageView(mContext, null, R.style.HotseatButton_Left);
			if (height > width)
				child.setBackgroundResource(R.drawable.hotseat_bg_left);
			else
				child.setBackgroundResource(R.drawable.hotseat_bg_right);
		} else if (position == 4) {
			child = new ImageView(mContext, null, R.style.HotseatButton_Right);
			if (height > width)
				child.setBackgroundResource(R.drawable.hotseat_bg_right);
			else
				child.setBackgroundResource(R.drawable.hotseat_bg_left);
		} else if (position == 1 || position == 3) {
			child = new ImageView(mContext, null, R.style.HotseatButton);
			child.setBackgroundResource(R.drawable.hotseat_bg_center);
		}
		child.setImageResource(R.drawable.blank_bg);
		child.setLayoutParams(lp);
		mItemHolder.addView(child, position);
		Log.i("hmg", "DockBar->removeSelectedItem");
		mItemHolder.removeView(mSelectedView);
//		DelOneDockIcon(position);
	}

	// 删除桌面选中的快捷方式
	private void DeleteZone(DragSource source, Object dragInfo) {
		final ItemInfo item = (ItemInfo) dragInfo;

		if (item.container == -1)
			return;

		if (item.container == LauncherSettings.Favorites.CONTAINER_DESKTOP) {
			if (item instanceof LauncherAppWidgetInfo) {
				mLauncher.removeAppWidget((LauncherAppWidgetInfo) item);
			}
		} else {
			if (source instanceof UserFolder) {
				final UserFolder userFolder = (UserFolder) source;
				final UserFolderInfo userFolderInfo = (UserFolderInfo) userFolder
						.getInfo();
				// Item must be a ShortcutInfo otherwise it couldn't have been
				// in the folder
				// in the first place.
				userFolderInfo.remove((ShortcutInfo) item);
			}
		}
		if (item instanceof UserFolderInfo) {
			final UserFolderInfo userFolderInfo = (UserFolderInfo) item;
			LauncherModel.deleteUserFolderContentsFromDatabase(mLauncher,
					userFolderInfo);
			mLauncher.removeFolder(userFolderInfo);
		} else if (item instanceof LauncherAppWidgetInfo) {
			final LauncherAppWidgetInfo launcherAppWidgetInfo = (LauncherAppWidgetInfo) item;
			final LauncherAppWidgetHost appWidgetHost = mLauncher
					.getAppWidgetHost();
			if (appWidgetHost != null) {
				final int appWidgetId = launcherAppWidgetInfo.appWidgetId;
				// Deleting an app widget ID is a void call but writes to disk
				// before returning
				// to the caller...
				new Thread("deleteAppWidgetId") {
					public void run() {
						appWidgetHost
								.deleteAppWidgetId(launcherAppWidgetInfo.appWidgetId);
					}
				}.start();
			}
		}
		LauncherModel.deleteItemFromDatabase(mLauncher, item);
	}

	// 判断当前选中对象是否已添加过
	private boolean ShutcutIsAdded(ShortcutInfo dragInfo) {
		boolean isAdded = false;
		ShortcutInfo info = null;

		for (int i = 0; i < mItemHolder.getChildCount(); i++) {
			View iv = mItemHolder.getChildAt(i);
			info = (ShortcutInfo) iv.getTag();
			if (info == null) {
				continue;
			} else if (dragInfo != null && info.title.equals(dragInfo.title))
				isAdded = true;
		}

		return isAdded;
	}

	// 保存DockBar上Icon的状态
	private void saveOneDockIcon(ShortcutInfo info, int position) {
		String title = (String) info.title;
		Intent intent = info.intent;
		String in = intent.toUri(0);
		Log.d("xx","title="+title);
		// long container = info.container;
		// int type = info.itemType;
		DockListProvider docklist = new DockListProvider(mContext);
		docklist.open();
		 docklist.insertTitle(title, in, position);
//		if(docklist.getItemByTitle(position)==null){
//		   docklist.insertTitle(title, in, position);
//		   Log.d("xx","insertTitle");
//	   } 
//		else{
//			docklist.updateTitle(title, in, position);
//		}
		docklist.close();
	}

	private void DelAllDockIcon() {
		DockListProvider docklist = new DockListProvider(mContext);
		docklist.open();
		docklist.deleteAll();
		docklist.close();
	}

	private void DelOneDockIcon(long position) {
		DockListProvider docklist = new DockListProvider(mContext);
		docklist.open();
		docklist.deleteTitle(position);
		docklist.close();
	}

	// 根据intent与title信息查找数据库中符号的对象
	static Cursor getShortcutInfo(Context context, String title, Intent intent) {
		final ContentResolver cr = context.getContentResolver();
		Cursor c = cr.query(LauncherSettings.Favorites.CONTENT_URI,
				new String[] { "title", "intent" }, "title=? and intent=?",
				new String[] { title, intent.toUri(0) }, null);
		if (c != null) {
			c.moveToFirst();
		}
		return c;
	}
}
