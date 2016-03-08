package org.cocos2dx.utils;

import java.lang.reflect.Method;
import java.util.Vector;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.annotation.TargetApi;
import android.app.ProgressDialog;
import android.content.ClipData;
import android.content.Context;
import android.content.Intent;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.os.Vibrator;
import android.telephony.TelephonyManager;
import android.view.Window;

import android.content.ClipboardManager;

public class PSNative {
	static Cocos2dxActivity mContext = null;
	static TelephonyManager mTelephonyManager = null;
	static Vibrator mVibrator = null;

	static PSDialog mCreatingDialog = null;
	static PSDialog mShowingDialog = null;
	static Vector<PSDialog> mShowingDialogs = null;
	static ProgressDialog spinner = null;
	static Drawable mAppIcon = null;

	static PSDialog.PSDialogListener mPSDialogListener = new PSDialog.PSDialogListener() {
		@Override
		public void onDismiss(PSDialog dialog) {
			showPreAlert();
		}
	};

	public static void init(Cocos2dxActivity context) {
		mContext = context;
		mTelephonyManager = (TelephonyManager) context
				.getSystemService(Context.TELEPHONY_SERVICE);
		mVibrator = (Vibrator) context
				.getSystemService(Context.VIBRATOR_SERVICE);

		mShowingDialogs = new Vector<PSDialog>();
		
		spinner = new ProgressDialog(context);
        spinner.requestWindowFeature(Window.FEATURE_NO_TITLE);
        spinner.setCancelable(false);
       // spinner.setMessage(getContext().getString(R.string.com_facebook_loading));
	}
	
	public static void showActivityIndicatorWithMsg(String msg){
		if (mContext == null) {
			return;
		}
		final String _msg = msg;
		mContext.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				spinner.setMessage(_msg);
				spinner.show();
			}
		});
	}
	public static void hideActivityIndicatorWithMsg(){
		if (mContext == null) {
			return;
		}

		mContext.runOnUiThread(new Runnable() {
			@Override
			public void run() {
					spinner.hide();
			}
		});
	}

	public static void setAppIcon(Drawable icon) {
		// 当对话框需要带上图像时，调用该方法。null表示不带图像
		mAppIcon = icon;
	}

	public static void createAlert(final String title, final String message,
			final Vector<String> buttonTitles, final int listener) {
		if (mContext == null) {
			return;
		}

		mContext.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				mCreatingDialog = new PSDialog(mContext).setCancelable(false)
						.setMessage(message).setTitle(title)
						.setLuaListener(listener)
						.setListener(mPSDialogListener).setIcon(mAppIcon);

				for (int i = 0; i < buttonTitles.size(); i++) {
					addAlertButton(buttonTitles.get(i));
				}

				if (mShowingDialog != null && mShowingDialog.isShowing()) {
					mShowingDialogs.add(mShowingDialog);
					mShowingDialog.hide();
				}

				mCreatingDialog.show();
				mShowingDialog = mCreatingDialog;
				mCreatingDialog = null;
			}
		});
	}

	@Deprecated
	/**
	 * this function will appear thread unsafe problem...
	 */
	public static void createAlert(final String title, final String message,
			final String defalutButtonTitle, final int listener) {
		if (mContext == null) {
			return;
		}

		mContext.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				mCreatingDialog = new PSDialog(mContext).setCancelable(false)
						.setMessage(message).setTitle(title)
						.setLuaListener(listener)
						.setListener(mPSDialogListener);

				addAlertButton(defalutButtonTitle);

				if (mShowingDialog != null && mShowingDialog.isShowing()) {
					mShowingDialogs.add(mShowingDialog);
					mShowingDialog.hide();
				}

				mCreatingDialog.show();
				mShowingDialog = mCreatingDialog;
				mCreatingDialog = null;
			}
		});
	}

	public static int addAlertButton(final String buttonTitle) {
		if (mCreatingDialog == null)
			return 0;

		return mCreatingDialog.addAlertButton(buttonTitle);
	}

	public static void showAlert() {
		if (mCreatingDialog == null) {
			return;
		}

		mContext.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if (mShowingDialog != null && mShowingDialog.isShowing()) {
					mShowingDialogs.add(mShowingDialog);
					mShowingDialog.hide();
				}

				mCreatingDialog.show();
				mShowingDialog = mCreatingDialog;
				mCreatingDialog = null;
			}
		});
	}

	public static void showAlertLua(final int luaFunctionId) {
		if (mCreatingDialog == null) {
			return;
		}

		mContext.runOnGLThread(new Runnable() {
			@Override
			public void run() {
				mCreatingDialog.setLuaListener(luaFunctionId);
				showAlert();
			}
		});
	}

	public static void cancelAlert() {
		if (mShowingDialog == null)
			return;

		mContext.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				mShowingDialog.dismiss();
				mShowingDialog = null;
			}
		});
	}

	public static void showPreAlert() {
		if (mShowingDialogs.size() > 0) {
			mShowingDialog = mShowingDialogs.firstElement();
			mShowingDialogs.remove(0);
			mShowingDialog.show();
		} else {
			mShowingDialog = null;
		}
	}

	public static void openURL(String url) {
		if (mContext == null) {
			return;
		}
		Uri uri = Uri.parse(url);
		mContext.startActivity(new Intent(Intent.ACTION_VIEW, uri));
	}

	public static String getInputText(String title, String message,
			String defaultValue) {
		return "";
	}

	private static String getMacAddress() {
		WifiManager wifi = (WifiManager) mContext
				.getSystemService(Context.WIFI_SERVICE);
		WifiInfo info = wifi.getConnectionInfo();
		if (info == null)
			return null;
		return info.getMacAddress();
	}

	public static String getOpenUDID() {
		String id = null;
		if (mTelephonyManager != null) {
			id = mTelephonyManager.getDeviceId();
		}
		if (id == null) {
			id = getMacAddress();
		}
		if (id == null) {
			id = "";
		}
		return id;
	}

	public static String getDeviceName() {
		return Build.USER;
	}

	public static void vibrate(long time) {
		if (mVibrator == null) {
			return;
		}
		mVibrator.vibrate(time);
	}

	public static void vibrate(long[] pattern, int repeatcout) {
		if (mVibrator == null) {
			return;
		}
		mVibrator.vibrate(pattern, repeatcout);
	}
	
	@SuppressWarnings("deprecation")
	@TargetApi(Build.VERSION_CODES.HONEYCOMB)
	public static void copyToClipBoard(final String context){
		mContext.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if(Build.VERSION.SDK_INT >=Build.VERSION_CODES.HONEYCOMB){           
				     // 包含新API的代码块
					//import android.content.ClipboardManager;
					ClipboardManager clipboardManager = (ClipboardManager)mContext.getSystemService( Context.CLIPBOARD_SERVICE );
					clipboardManager.setPrimaryClip(ClipData.newPlainText(null, context));
					//if (clipboardManager.hasPrimaryClip()){
					//    clipboardManager.getPrimaryClip().getItemAt(0).getText();
					//}

				}else{
				     // 包含旧的API的代码块
					//import android.text.ClipboardManager;
					//import android.text.ClipboardManager;
					android.text.ClipboardManager clipboardManager = (android.text.ClipboardManager) mContext.getSystemService(Context.CLIPBOARD_SERVICE);
					clipboardManager.setText(context);
					//if (clipboardManager.hasText()){
					//    clipboardManager.getText();
					//}

				}
			}
		});
		
		
		
	}
	
	
	public static Context getAppContext() {
		return mContext;
	}
}