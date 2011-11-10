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
	private final static  String GOODS_TABLE = "goods";//��Ʒ��
	private final static  String LIST_TABLE = "shopping_list";//�����嵥
	private final static  String GOODS_LIST_TABLE = "goods_shopping_list";//�м��
	
	//��ΪSimpleCursorAdapter�����б����и��ֶ���_id,����ᱨ��
	//���Դ˴�ʹ��_id
	public final static  String FIELD_ID="_id";
	public final static  String FIELD_TEXT="betty_text";

	public DBAdapter(Context context) {
		super(context,DATABASE_NAME,null,DATABASE_VERSION);
	}
/*
 * �����嵥����Ʒ��
 * (non-Javadoc)
 * @see android.database.sqlite.SQLiteOpenHelper#onCreate(android.database.sqlite.SQLiteDatabase)
 */
	@Override
	public void onCreate(SQLiteDatabase db) {
	
	if(db==null){
		db = this.getWritableDatabase();
	}
	//��������ڣ��������ݱ�
	//��Ʒ��,��Ʒ���ƣ��۸񣬱�ע(��Ʒ������)
	db.execSQL("create table if not exists " + GOODS_TABLE
		      + "(id integer primary key,name varchar,price double,remark varchar(200),_id varchar(200))");
	
	//�����嵥���嵥���ƣ�����ʱ�䣬��ע(�嵥Ŀ�ĵ�����)
	db.execSQL("create table if not exists " + LIST_TABLE
			+ "(id integer primary key,name varchar,shopping_date timestamp,remark varchar(200))");
	
	//�м��һ���嵥���������Ʒ��������Ʒid��
	db.execSQL("create table if not exists " + GOODS_LIST_TABLE
			+ "(id integer primary key,shopping_list_id integer,goods_id integer,state boolean,number double)");
	}
	
	//goods���в�������
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
	
	//����Ƿ�ͬ�������û��ͬ�������������
	public int insertGoods(String name){
		SQLiteDatabase db = this.getWritableDatabase();
		Cursor cursor = db.query(GOODS_TABLE, null, "name = ?", new String[]{name}, null, null, null);
		if(cursor.moveToNext()){
			return 0;//0 �Ѿ����ڼ�¼
		}else{
			//û�м�¼����Ҫ����
			close(db,cursor);
			Goods goods = new Goods();
			goods.setName(name);
			insertGoods(goods);
			return 1;//1 ����ɹ�
		}
	}
	
	//��Ʒģ����ѯ
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
	//��Ʒģ����ѯ
	public Cursor findGoodsCoursorByName(String name){
		SQLiteDatabase db = this.getWritableDatabase();
		Cursor cursor = db.query(GOODS_TABLE, null, "name like %?%", new String[]{name}, null, null, null);
		close(db,cursor);
		return cursor;
	}
	//��Ʒģ����ѯ
	public Cursor findGoodsName(String name){
		SQLiteDatabase db = this.getWritableDatabase();
		Cursor cursor = db.rawQuery("select name as _id  from goods where name like ?",  new String[]{name + "%"});
		return cursor;
	}
	
	//�޸���Ʒ��Ϣ
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
	//ɾ����Ʒ��Ϣ
	public  void deleteGoods(int id){
		SQLiteDatabase db = this.getWritableDatabase();
		String[] param = {String.valueOf(id)};
		db.delete(GOODS_TABLE, "id=?", param);
		close(db,null);
	}
	//��ȡ��Ʒ,�����鿴��Ʒ������
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
	//��ȡ��Ʒ,�����鿴��Ʒ������,����Corsor
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
	//����ShoppingList Cursor
	public  Cursor queryShoppingListCursor(int id){
		
		SQLiteDatabase db = this.getReadableDatabase();
		String[] column = {"id","name","shopping_date","remark"};
		String[] param = {String.valueOf(id)};
		Cursor cursor = db.query(LIST_TABLE, column, "id = ?", param, null, null, null);
		close(db,null);
		return cursor;
	}
	//��ȡ������Ʒ,չʾ�������е���Ʒ
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
	//��ȡ������Ʒ,չʾ�������е���Ʒ,����Cursor
	public Cursor findGoodsListCursor(){
		SQLiteDatabase db = this.getReadableDatabase();
		Cursor cursor = db.query(GOODS_TABLE, null,null, null, null, null, null);
		close(db,null);
		return cursor;
	}
	//�����嵥�в�������,����������Ҫ�����м��
	public  void insertList(ShoppingList shoppingList){
		
		SQLiteDatabase db = this.getWritableDatabase();
		ContentValues values = new  ContentValues();
		values.put("name", shoppingList.getName());
		values.put("shopping_date", DateUtil.dateToString(shoppingList.getDate()));//ʱ���д�����
		values.put("remark", shoppingList.getRemark());
		
		List<Goods> goodsList = shoppingList.getGoodsList();
		
		long shoppingList_id = db.insert(LIST_TABLE, null, values);
		if(goodsList!=null){
		for(Goods goods:goodsList){
			//��������״̬��Ϣ�����뵽�м��.�м����Ҫ�嵥��id
			insertGoodsListTable(db,goods,shoppingList_id);
		}
		}
		close(db,null);
	}
	//�м�����ݲ���
	private  void insertGoodsListTable(SQLiteDatabase db, Goods goods,long shoppingList_id) {
		
		ContentValues values = new  ContentValues();
		values.put("shopping_list_id", shoppingList_id);
		values.put("goods_id", goods.getId());
		values.put("number", goods.getNumber());
		values.put("state", goods.getState());
		db.insert(GOODS_LIST_TABLE, "id", values);
	}
	
	//�޸Ĺ����嵥����
	public  void upateList(ShoppingList shoppingList){
		
		SQLiteDatabase db = this.getWritableDatabase();
		ContentValues values = new  ContentValues();
		values.put("name", shoppingList.getName());
		values.put("shopping_date", DateUtil.dateToString(shoppingList.getDate()));//ʱ���д�����
		values.put("remark", shoppingList.getRemark());
		List<Goods> goodsList = shoppingList.getGoodsList();
		if(goodsList!=null){
	
		
		for(Goods goods:goodsList){
			//��������״̬��Ϣ�����뵽�м��.�м����Ҫ�嵥��id
			updateGoodsListTable(db,goods,shoppingList.getId());
		}
		}
		String[] param = new String[]{String.valueOf(shoppingList.getId())};
		
		db.update(LIST_TABLE, values, "id=?",param);
		close(db,null);
	}
	
	
	//�����м��
	private  void updateGoodsListTable(SQLiteDatabase db, Goods goods,
			int id) {
		
		ContentValues values = new  ContentValues();
		values.put("number", goods.getNumber());
		values.put("state", goods.getState());
		String[] param = {String.valueOf(id),String.valueOf(goods.getId())};
		db.update(GOODS_LIST_TABLE,values, "shopping_list_id = ? and goods_id = ?",param);
		
	}
	//��ѯ�嵥����ʱ�䵹���г������嵥
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
	//��ѯ�嵥����ʱ�䵹���г������嵥,����Cursor
public  Cursor findShoppingListCorsor() throws ParseException{
		
		SQLiteDatabase db = this.getReadableDatabase();
		Cursor cursor = db.query(LIST_TABLE, null,null, null, null, null, null);
		close(db,null);
		return cursor;
	}
	//���嵥����ģ����ѯ
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
//���嵥����ģ����ѯ
public  Cursor findShoppingListByNameCursor(String name) throws ParseException{
	
	SQLiteDatabase db = this.getReadableDatabase();
	Cursor cursor = db.query(LIST_TABLE, null,"name like %?%", new String[]{name}, null, null, null);
	close(db,null);
	return cursor;
}
	//�鿴�嵥�����Ʒ,��Ҫ�嵥��id,�漰���м�����Ʒ������ݹ���
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
	
	//ɾ���嵥�Լ����е�����
	public  void deleteShoppingList(int id){
		
		SQLiteDatabase db = this.getWritableDatabase();
		String[] param = {String.valueOf(id)};
		db.delete(LIST_TABLE, "id=?", param);//shoppingList
		db.delete(GOODS_LIST_TABLE, "id=?", param);//�м������
		close(db,null);
	}
	
	//ɾ���м������
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
