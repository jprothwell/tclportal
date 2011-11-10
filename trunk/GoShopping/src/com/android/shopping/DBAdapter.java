package com.android.shopping;

import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import com.android.shopping.bean.Goods;
import com.android.shopping.bean.ShoppingList;

public class DBAdapter extends SQLiteOpenHelper{

	private final static  String DATABASE_NAME = "shoppinglist_db";
	private final static  int DATABASE_VERSION = 1;
	private final static  String GOODS_TABLE = "goods";//商品表
	private final static  String LIST_TABLE = "shopping_list";//购物清单
	private final static  String GOODS_LIST_TABLE = "goods_shopping_list";//中间表
	
	//因为SimpleCursorAdapter构造中必须有个字段是_id,否则会报错
	//所以此处使用_id
	public final static  String FIELD_ID="_id";
	public final static  String FIELD_TEXT="betty_text";

	public DBAdapter(Context context) {
		super(context,DATABASE_NAME,null,DATABASE_VERSION);
	}
/*
 * 创建清单表，物品表
 * (non-Javadoc)
 * @see android.database.sqlite.SQLiteOpenHelper#onCreate(android.database.sqlite.SQLiteDatabase)
 */
	@Override
	public void onCreate(SQLiteDatabase db) {
	
	if(db==null){
		db = this.getWritableDatabase();
	}
	//如果不存在，创建数据表
	//商品表,物品名称，价格，备注(商品的描述)
	db.execSQL("create table if not exists " + GOODS_TABLE
		      + "(id integer primary key,name varchar,price double,remark varchar(200),_id varchar(200))");
	
	//购物清单，清单名称，提醒时间，备注(清单目的的描述)
	db.execSQL("create table if not exists " + LIST_TABLE
			+ "(id integer primary key,name varchar,shopping_date timestamp,remark varchar(200))");
	
	//中间表，一个清单包含多个商品，包含商品id，
	db.execSQL("create table if not exists " + GOODS_LIST_TABLE
			+ "(id integer primary key,shopping_list_id integer,goods_id integer,state boolean,number double)");
	}
	
	//goods表中插入数据
	public  void insertGoods(Goods goods){
		
		SQLiteDatabase db = this.getWritableDatabase();
		ContentValues values = new  ContentValues();
		values.put("name", goods.getName());
		values.put("remark",goods.getRemark());
		values.put("price", goods.getPrice());
//		db.execSQL("insert into "+ GOODS_TABLE +"(name,remark,price) values (?,?,?)");
		db.insert(GOODS_TABLE, null, values);
		close(db,null);
	}
	
	//检测是否同名，如果没有同名，则插入数据
	public int insertGoods(String name){
		SQLiteDatabase db = this.getWritableDatabase();
		Cursor cursor = db.query(GOODS_TABLE, null, "name = ?", new String[]{name}, null, null, null);
		if(cursor.moveToNext()){
			return 0;//0 已经存在记录
		}else{
			//没有记录，需要保存
			close(db,cursor);
			Goods goods = new Goods();
			goods.setName(name);
			insertGoods(goods);
			return 1;//1 保存成功
		}
	}
	
	//商品模糊查询
	public List<Goods> findGoodsByName(String name){
		SQLiteDatabase db = this.getWritableDatabase();
		Cursor cursor = db.query(GOODS_TABLE, null, "name like %?%", new String[]{name}, null, null, null);
		List<Goods> list = new ArrayList<Goods>();
		while(cursor.moveToNext()){
			Goods goods = new Goods();
			goods.setId(cursor.getInt(0));
			goods.setName(cursor.getString(1));
			goods.setRemark(cursor.getString(2));
			list.add(goods);
		}
		close(db,cursor);
		return list;
	}
	//商品模糊查询
	public Cursor findGoodsCoursorByName(String name){
		SQLiteDatabase db = this.getWritableDatabase();
		Cursor cursor = db.query(GOODS_TABLE, null, "name like %?%", new String[]{name}, null, null, null);
		close(db,cursor);
		return cursor;
	}
	//商品模糊查询
	public Cursor findGoodsName(String name){
		SQLiteDatabase db = this.getWritableDatabase();
		Cursor cursor = db.rawQuery("select name as _id  from goods where name like ?",  new String[]{name + "%"});
		return cursor;
	}
	
	//修改商品信息
	public  void updateGoos(Goods goods){
		SQLiteDatabase db = this.getWritableDatabase();
		ContentValues values = new  ContentValues();
		values.put("name", goods.getName());
		values.put("remark",goods.getRemark());
		values.put("price", goods.getPrice());
		String[] param = new String[]{String.valueOf(goods.getId())};
		db.update(GOODS_TABLE, values, "id=?",param);
		close(db,null);
	}
	//删除商品信息
	public  void deleteGoods(int id){
		SQLiteDatabase db = this.getWritableDatabase();
		String[] param = {String.valueOf(id)};
		db.delete(GOODS_TABLE, "id=?", param);
		close(db,null);
	}
	//获取商品,单纯查看商品的属性
	public  Goods queryGoods(int id){
		
		SQLiteDatabase db = this.getReadableDatabase();
		String[] column = {"id","name","remark"};
		String[] param = {String.valueOf(id)};
		Cursor cursor = db.query(GOODS_TABLE, column, "id = ?", param, null, null, null);
		Goods goods = new Goods();
		goods.setId(cursor.getInt(0));
		goods.setName(cursor.getString(1));
		goods.setRemark(cursor.getString(2));
		close(db,cursor);
		return goods;
	}
	//获取商品,单纯查看商品的属性,返回Corsor
	public Cursor queryGoodsCousor(int id){
		SQLiteDatabase db = this.getReadableDatabase();
		String[] column = {"id","name","remark"};
		String[] param = {String.valueOf(id)};
		Cursor cursor = db.query(GOODS_TABLE, column, "id = ?", param, null, null, null);
		cursor.moveToFirst(); 
		close(db,cursor);
		return cursor;
	}
	public  ShoppingList queryShoppingList(int id){
		
		SQLiteDatabase db = this.getReadableDatabase();
		String[] column = {"id","name","shopping_date","remark"};
		String[] param = {String.valueOf(id)};
		Cursor cursor = db.query(LIST_TABLE, column, "id = ?", param, null, null, null);
		ShoppingList shoppinglist = new ShoppingList();
		cursor.moveToFirst(); 
			shoppinglist.setId(cursor.getInt(0));
			shoppinglist.setName(cursor.getString(1));
			shoppinglist.setDate(DateUtil.stringToDate(cursor.getString(2)));
			shoppinglist.setRemark(cursor.getString(3));
		
		close(db,null);
		return shoppinglist;
	}
	//返回ShoppingList Cursor
	public  Cursor queryShoppingListCursor(int id){
		
		SQLiteDatabase db = this.getReadableDatabase();
		String[] column = {"id","name","shopping_date","remark"};
		String[] param = {String.valueOf(id)};
		Cursor cursor = db.query(LIST_TABLE, column, "id = ?", param, null, null, null);
		close(db,null);
		return cursor;
	}
	//获取所有商品,展示返回所有的商品
	public  List<Goods> findGoodsList(){
		SQLiteDatabase db = this.getReadableDatabase();
		Cursor cursor = db.query(GOODS_TABLE, null,null, null, null, null, null);
		List<Goods> list = new ArrayList<Goods>();
		while(cursor.moveToNext()){
			Goods goods = new Goods();
			goods.setId(cursor.getInt(0));
			goods.setName(cursor.getString(1));
			goods.setRemark(cursor.getString(2));
			list.add(goods);
		}
		close(db,cursor);
		return list;
	}
	//获取所有商品,展示返回所有的商品,返回Cursor
	public Cursor findGoodsListCursor(){
		SQLiteDatabase db = this.getReadableDatabase();
		Cursor cursor = db.query(GOODS_TABLE, null,null, null, null, null, null);
		close(db,null);
		return cursor;
	}
	//购物清单中插入数据,部分数据需要插入中间表，
	public  void insertList(ShoppingList shoppingList){
		
		SQLiteDatabase db = this.getWritableDatabase();
		ContentValues values = new  ContentValues();
		values.put("name", shoppingList.getName());
		values.put("shopping_date", DateUtil.dateToString(shoppingList.getDate()));//时间有待更改
		values.put("remark", shoppingList.getRemark());
		
		List<Goods> goodsList = shoppingList.getGoodsList();
		
		long shoppingList_id = db.insert(LIST_TABLE, null, values);
		if(goodsList!=null){
		for(Goods goods:goodsList){
			//将数量，状态信息，插入到中间表.中间表需要清单的id
			insertGoodsListTable(db,goods,shoppingList_id);
		}
		}
		close(db,null);
	}
	//中间表数据插入
	private  void insertGoodsListTable(SQLiteDatabase db, Goods goods,long shoppingList_id) {
		
		ContentValues values = new  ContentValues();
		values.put("shopping_list_id", shoppingList_id);
		values.put("goods_id", goods.getId());
		values.put("number", goods.getNumber());
		values.put("state", goods.getState());
		db.insert(GOODS_LIST_TABLE, "id", values);
	}
	
	//修改购物清单数据
	public  void upateList(ShoppingList shoppingList){
		
		SQLiteDatabase db = this.getWritableDatabase();
		ContentValues values = new  ContentValues();
		values.put("name", shoppingList.getName());
		values.put("shopping_date", DateUtil.dateToString(shoppingList.getDate()));//时间有待更改
		values.put("remark", shoppingList.getRemark());
		List<Goods> goodsList = shoppingList.getGoodsList();
		if(goodsList!=null){
	
		
		for(Goods goods:goodsList){
			//将数量，状态信息，插入到中间表.中间表需要清单的id
			updateGoodsListTable(db,goods,shoppingList.getId());
		}
		}
		String[] param = new String[]{String.valueOf(shoppingList.getId())};
		
		db.update(LIST_TABLE, values, "id=?",param);
		close(db,null);
	}
	
	
	//更新中间表
	private  void updateGoodsListTable(SQLiteDatabase db, Goods goods,
			int id) {
		
		ContentValues values = new  ContentValues();
		values.put("number", goods.getNumber());
		values.put("state", goods.getState());
		String[] param = {String.valueOf(id),String.valueOf(goods.getId())};
		db.update(GOODS_LIST_TABLE,values, "shopping_list_id = ? and goods_id = ?",param);
		
	}
	//查询清单，以时间倒序列出所有清单
	public  List<ShoppingList> findShoppingList(){
		
		SQLiteDatabase db = this.getReadableDatabase();
		Cursor cursor = db.query(LIST_TABLE, null,null, null, null, null, null);
		List<ShoppingList> list = new ArrayList<ShoppingList>();
		while(cursor.moveToNext()){
			ShoppingList shoppingList = new ShoppingList();
			shoppingList.setId(cursor.getInt(0));
			shoppingList.setName(cursor.getString(1));
			shoppingList.setDate(DateUtil.stringToDate(cursor.getString(2)));
			shoppingList.setRemark(cursor.getString(3));
			list.add(shoppingList);
		}
		close(db,cursor);
		return list;
	}
	//查询清单，以时间倒序列出所有清单,返回Cursor
public  Cursor findShoppingListCorsor() throws ParseException{
		
		SQLiteDatabase db = this.getReadableDatabase();
		Cursor cursor = db.query(LIST_TABLE, null,null, null, null, null, null);
		close(db,null);
		return cursor;
	}
	//按清单名称模糊查询
public  List<ShoppingList> findShoppingListByName(String name) throws ParseException{
		
		SQLiteDatabase db = this.getReadableDatabase();
		Cursor cursor = db.query(LIST_TABLE, null,"name like %?%", new String[]{name}, null, null, null);
		List<ShoppingList> list = new ArrayList<ShoppingList>();
		while(cursor.moveToNext()){
			ShoppingList shoppingList = new ShoppingList();
			shoppingList.setId(cursor.getInt(0));
			shoppingList.setName(cursor.getString(1));
			shoppingList.setDate(DateUtil.stringToDate(cursor.getString(2)));
			shoppingList.setRemark(cursor.getString(3));
			list.add(shoppingList);
		}
		close(db,cursor);
		return list;
	}
//按清单名称模糊查询
public  Cursor findShoppingListByNameCursor(String name) throws ParseException{
	
	SQLiteDatabase db = this.getReadableDatabase();
	Cursor cursor = db.query(LIST_TABLE, null,"name like %?%", new String[]{name}, null, null, null);
	close(db,null);
	return cursor;
}
	//查看清单里的商品,需要清单的id,涉及到中间表和商品表的数据关联
	public  List<Goods> findGoodsInShoppingList(int id){
		
		SQLiteDatabase db = this.getReadableDatabase();
		String[] param = {String.valueOf(id)};
		StringBuilder sql = new StringBuilder();
		sql.append("select g.id,g.name,g.price,g.remark,gt.state,gt.number from ");
		sql.append(GOODS_TABLE);
		sql.append(" g,");
		sql.append(GOODS_LIST_TABLE);
		sql.append(" gt where g.id = gt.goods_id and gt.shopping_list_id = ?");
		//System.out.println("-"+sql.toString());
		Cursor cursor = db.rawQuery(sql.toString(), param);
		
		List<Goods> list = new ArrayList<Goods>();
		while(cursor.moveToNext()){
			Goods goods = new Goods();
			goods.setId(cursor.getInt(0));
			goods.setName(cursor.getString(1));
			goods.setPrice(cursor.getDouble(2));
			goods.setRemark(cursor.getString(3));
			goods.setState(cursor.getInt(4));
			goods.setNumber(cursor.getDouble(5));
			list.add(goods);
		}
		close(db,cursor);
		return list;
	}
	public  Cursor findGoodsInShoppingListCursor(int id){
		SQLiteDatabase db = this.getReadableDatabase();
		String[] param = {String.valueOf(id)};
		StringBuilder sql = new StringBuilder();
		sql.append("select g.id,g.name,g.price,g.remark,gt.state,gt.number from ");
		sql.append(GOODS_TABLE);
		sql.append(" g,");
		sql.append(GOODS_LIST_TABLE);
		sql.append(" gt where g.id = gt.goods_id and gt.shopping_list_id = ?");
		//System.out.println("-"+sql.toString());
		Cursor cursor = db.rawQuery(sql.toString(), param);
		close(db,null);
		return cursor;
	}
	
	//删除清单以及其中的数据
	public  void deleteShoppingList(int id){
		
		SQLiteDatabase db = this.getWritableDatabase();
		String[] param = {String.valueOf(id)};
		db.delete(LIST_TABLE, "id=?", param);//shoppingList
		db.delete(GOODS_LIST_TABLE, "id=?", param);//中间表数据
		close(db,null);
	}
	
	//删除中间表数据
	public  void deleteGoodsInShppingList(int shoppingList,int goods){
		
		SQLiteDatabase db = this.getWritableDatabase();
		String[] param = {String.valueOf(shoppingList),String.valueOf(goods)};
		db.delete(GOODS_LIST_TABLE, "shopping_list_id = ? and goods_id = ?", param);
		close(db,null);
	}

	public void close(SQLiteDatabase sd,Cursor cursor){

		if(cursor!=null){
			cursor.close();
		}
		if(sd!=null){
			sd.close();
		}
		
	}
	public SQLiteDatabase getDB(){
		SQLiteDatabase db = this.getWritableDatabase();
		return db;
		
	}

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldversion, int newversion) {
		onCreate(db);
	}
}
