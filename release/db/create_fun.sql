  
CREATE OR REPLACE FUNCTION bc_imei_query(in_sdate date, in_edate date, in_type character varying, in_invcode character varying)
  RETURNS SETOF record AS
$BODY$
DECLARE
	v_rec RECORD;
	
BEGIN
  --串码流向
	return query  (
	SELECT c.*, d.wh_name, e.product_name, f.vouch_name
	FROM (
		SELECT a.no,a.imei,a.vouchs_id,a.wh_code,a.vouch_type,
			a.product_code,a.bus_date,a.created,a.creater,a.memo,b.supplie_name as bus_name
		FROM rd_in_imei a, ba_suppliers b 
		where a.bus_code=b.supplie_code AND a.vouch_type='01' 
			AND a.product_code LIKE in_invcode 
			AND a.bus_date>=in_sdate AND a.bus_date<=in_edate 
	UNION 
		SELECT a.no,a.imei,a.vouchs_id,a.wh_code,a.vouch_type,
			a.product_code,a.bus_date,a.created,a.creater,a.memo,b.cus_name as bus_name
		FROM rd_out_imei a, ba_customer b 
		where a.bus_code=b.cus_code AND (a.vouch_type='02' OR a.vouch_type='11')
			AND a.product_code LIKE in_invcode 
			AND a.bus_date>=in_sdate AND a.bus_date<=in_edate 
	UNION 
		SELECT a.no,a.imei,a.vouchs_id,a.wh_code,a.vouch_type,
			a.product_code,a.bus_date,a.created,a.creater,a.memo,b.cus_name as bus_name
		FROM rd_in_imei a, ba_customer b 
		where a.bus_code=b.cus_code AND (a.vouch_type='12' OR a.vouch_type='15')
			AND a.product_code LIKE in_invcode 
			AND a.bus_date>=in_sdate AND a.bus_date<=in_edate
	UNION 
		SELECT a.no,a.imei,a.vouchs_id,a.wh_code,a.vouch_type,
			a.product_code,a.bus_date,a.created,a.creater,a.memo,b.supplie_name as bus_name
		FROM rd_out_imei a, ba_suppliers b 
		where a.bus_code=b.supplie_code AND a.vouch_type='14' 
			AND a.product_code LIKE in_invcode 
			AND a.bus_date>=in_sdate AND a.bus_date<=in_edate 
	UNION 
		SELECT a.no,a.imei,a.vouchs_id,a.out_wh_code as wh_code,a.vouch_type,
			a.product_code,a.bus_date,a.created,a.creater,a.memo,b.wh_name as bus_name
		FROM rd_trans_imei a, ba_ware_house b
		where a.in_wh_code=b.wh_code
			AND a.product_code LIKE in_invcode 
			AND a.bus_date>=in_sdate AND a.bus_date<=in_edate 
	) c, ba_ware_house d, ba_product e ,vouch_type f
	where c.wh_code=d.wh_code AND c.product_code=e.product_code 
		AND c.vouch_type=f.vouch_type
		AND e.type_id LIKE in_type 
	ORDER BY c.bus_date,c.imei ASC );
	
	
	
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;


CREATE OR REPLACE FUNCTION bc_imei_query_by(in_imei character varying)
  RETURNS SETOF record AS
$BODY$
DECLARE
	v_rec RECORD;
	
BEGIN
  --串码流向
	return query  (
	SELECT c.*, d.wh_name, e.product_name, f.vouch_name
	FROM (
		SELECT a.no,a.imei,a.vouchs_id,a.wh_code,a.vouch_type,
			a.product_code,a.bus_date,a.created,a.creater,a.memo,b.supplie_name as bus_name
		FROM rd_in_imei a, ba_suppliers b 
		where a.bus_code=b.supplie_code AND a.vouch_type='01' 
			AND imei LIKE in_imei
	UNION 
		SELECT a.no,a.imei,a.vouchs_id,a.wh_code,a.vouch_type,
			a.product_code,a.bus_date,a.created,a.creater,a.memo,b.cus_name as bus_name
		FROM rd_out_imei a, ba_customer b 
		where a.bus_code=b.cus_code AND (a.vouch_type='02' OR a.vouch_type='11')
			AND imei LIKE in_imei
	UNION 
		SELECT a.no,a.imei,a.vouchs_id,a.wh_code,a.vouch_type,
			a.product_code,a.bus_date,a.created,a.creater,a.memo,b.cus_name as bus_name
		FROM rd_in_imei a, ba_customer b 
		where a.bus_code=b.cus_code AND (a.vouch_type='12' OR a.vouch_type='15')
			AND imei LIKE in_imei
	UNION 
		SELECT a.no,a.imei,a.vouchs_id,a.wh_code,a.vouch_type,
			a.product_code,a.bus_date,a.created,a.creater,a.memo,b.supplie_name as bus_name
		FROM rd_out_imei a, ba_suppliers b 
		where a.bus_code=b.supplie_code AND a.vouch_type='14' 
			AND imei LIKE in_imei
	UNION 
		SELECT a.no,a.imei,a.vouchs_id,a.out_wh_code as wh_code,a.vouch_type,
			a.product_code,a.bus_date,a.created,a.creater,a.memo,b.wh_name as bus_name
		FROM rd_trans_imei a, ba_ware_house b
		where a.in_wh_code=b.wh_code
			AND imei LIKE in_imei
	) c, ba_ware_house d, ba_product e ,vouch_type f
	where c.wh_code=d.wh_code AND c.product_code=e.product_code 
		AND c.vouch_type=f.vouch_type
	ORDER BY c.bus_date,c.imei ASC );
	
	
	
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;


CREATE OR REPLACE FUNCTION fa_transceivers_summary(in_sdate date, in_edate date, in_whcode character varying, in_invtypecode character varying, in_invcode character varying)
  RETURNS SETOF record AS
$BODY$
DECLARE
	v_rec RECORD;
	strat_sum numeric; --期初数量
	i_qty_sum numeric; --期初累记入库数量
	o_qty_sum numeric; --期初累记出库数量
	end_sum numeric;   --期未数量
BEGIN
	-- 存货收发存汇总表
	end_sum := 0;
	strat_sum := 0;
	i_qty_sum := 0;
	o_qty_sum := 0;
	drop table if exists temp_fa_tr_summary;

  -- 取得期末
	CREATE TEMP TABLE temp_fa_tr_summary AS 
		SELECT b.product_code,0.0 as be_quantity,0.0 as be_cost,0.0 as be_money, 
		0.0 as in_quantity,0.0 as in_cost, 0.0 as in_money, 
		0.0 as out_quantity,0.0 as out_cost, 0.0 as out_money,
		sum(b.st_quantity) as st_quantity,
		CASE WHEN sum(b.st_quantity)>0 THEN sum(b.st_money)/sum(b.st_quantity)
		ELSE 0
		END as st_cost,sum(b.st_money) as st_money FROM 
			( SELECT wh_code,product_code,max(id) as maxid 
					FROM fa_subsidiary  
					WHERE bus_date<=in_edate
					GROUP BY product_code,wh_code) a,
			fa_subsidiary b
		WHERE a.maxid=b.id AND b.wh_code LIKE in_whcode AND b.product_code LIKE in_invcode
		GROUP BY b.product_code;
		--计算入库
		UPDATE temp_fa_tr_summary SET in_quantity=b.in_quantity, in_money=b.in_money
		FROM ( SELECT product_code,sum(in_quantity) as in_quantity,sum(in_money) as in_money
			 FROM fa_subsidiary WHERE rd_flag=1 
			 AND bus_date>=in_sdate AND bus_date<=in_edate AND wh_code LIKE in_whcode AND product_code LIKE in_invcode
			 GROUP BY product_code) b
	  WHERE temp_fa_tr_summary.product_code=b.product_code;
		
		--计算出库
		UPDATE temp_fa_tr_summary SET out_quantity=b.out_quantity, out_money=b.out_money
		FROM ( SELECT product_code,sum(out_quantity) as out_quantity,sum(out_money) as out_money
			 FROM fa_subsidiary WHERE rd_flag=2 
			 AND bus_date>=in_sdate AND bus_date<=in_edate AND wh_code LIKE in_whcode AND product_code LIKE in_invcode
			 GROUP BY product_code) b
	  WHERE temp_fa_tr_summary.product_code=b.product_code;
		--计算期初
		UPDATE temp_fa_tr_summary SET be_quantity= st_quantity - in_quantity + out_quantity ,
				be_money = st_money - in_money + out_money;
		UPDATE temp_fa_tr_summary SET be_cost= be_money/be_quantity 
				WHERE be_quantity > 0; 
		UPDATE temp_fa_tr_summary SET in_cost= in_money/in_quantity 
				WHERE in_quantity > 0; 
		UPDATE temp_fa_tr_summary SET out_cost= out_money/out_quantity 
				WHERE out_quantity > 0; 
	return query  (SELECT a.*,b.product_name,b.style,b.purchase_unit as unit FROM temp_fa_tr_summary a,ba_product b WHERE a.product_code=b.product_code ) ;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;


CREATE OR REPLACE FUNCTION pu_settle_remain(in_sdate date, in_edate date, in_ventypecode character varying, in_vencode character varying, in_invtypecode character varying, in_invcode character varying)
  RETURNS SETOF record AS
$BODY$
DECLARE
    v_rec RECORD;
		end_num integer;
BEGIN
   end_num := 0;
	 --采购结算余额表
   return query   ( 
			SELECT e.*, 
				COALESCE(h.settleSumQuantity,0) as settleSumQuantity,
				COALESCE(h.settleSumMoney,0) as settleSumMoney,
				COALESCE(h.settleSumAmount,0) as settleSumAmount,
				COALESCE(f.startSumQuantity,0)-COALESCE(g.startSettleSumQuantity,0) as startSumQuantity, 
				COALESCE(f.startSumMoney,0)-COALESCE(g.startSettleSumMoney,0) as startSumMoney,
				COALESCE(g.startSettleSumQuantity,0) as startSettleSumQuantity, 
				COALESCE(g.startSettleSumMoney,0) as startSettleSumMoney,
				COALESCE(f.startSumQuantity,0)-COALESCE(g.startSettleSumQuantity,0)+e.sumQuantity-COALESCE(h.settleSumQuantity,0) as endSumQuantity, 
				COALESCE(f.startSumMoney,0)-COALESCE(g.startSettleSumMoney,0)+e.sumMoney-COALESCE(h.settleSumMoney,0) as endSumMoney
			FROM 
				--本期入库
				(SELECT a.supplier_id,c.supplie_name,b.product_code,d.product_name,
						sum(b.quantity) as sumQuantity,sum(b.money) as sumMoney
					FROM rd_record a, rd_records b, ba_suppliers c, ba_product d
					WHERE a.rd_no=b.rd_no AND is_handle=true
						AND (a.vouch_type='01' OR a.vouch_type='14')
						AND a.supplier_id=c.supplie_code AND b.product_code=d.product_code
						AND a.bus_date>=in_sdate AND a.bus_date<=in_edate
						AND c.supplie_type LIKE in_venTypeCode AND a.supplier_id LIKE in_venCode
						AND b.product_code LIKE in_invcode AND d.type_id LIKE in_invTypeCode
					GROUP BY a.supplier_id,b.product_code,d.product_name,c.supplie_name ) e
				LEFT JOIN 
					(SELECT a.supplier_id, b.product_code, 
						sum(b.quantity) as startSumQuantity, sum(b.money) as startSumMoney
						FROM rd_record a, rd_records b
						WHERE a.rd_no=b.rd_no AND is_handle=true
						AND (a.vouch_type='01' OR a.vouch_type='14')
						AND a.bus_date<in_sdate 
						GROUP BY a.supplier_id,b.product_code ) f
				ON e.supplier_id=f.supplier_id AND e.product_code=f.product_code
				LEFT JOIN 
					(SELECT a.supplier_id, b.product_code, 
						sum(b.quantity) as startSettleSumQuantity, sum(b.quantity*c.unit_price) as startSettleSumMoney
						FROM pu_settle_vouch a, pu_settle_vouchs b, rd_records c
						WHERE a.no=b.settle_no AND is_handle=true AND ( bus_type='01' OR bus_type='02' )
						AND b.rd_no=c.rd_no AND b.product_code=c.product_code
						AND a.settle_date<in_sdate 
						GROUP BY a.supplier_id,b.product_code ) g
				ON e.supplier_id=g.supplier_id AND e.product_code=g.product_code
				--本期结算
				LEFT JOIN 
					(SELECT a.supplier_id, b.product_code, 
						sum(b.quantity) as settleSumQuantity, sum(b.quantity*c.unit_price) as settleSumMoney,
						sum(b.amount) as settleSumAmount
						FROM pu_settle_vouch a, pu_settle_vouchs b, rd_records c
						WHERE a.no=b.settle_no AND is_handle=true AND ( bus_type='01' OR bus_type='02' )
						AND b.rd_no=c.rd_no AND b.product_code=c.product_code
						AND a.settle_date>=in_sdate AND a.settle_date<=in_edate
						GROUP BY a.supplier_id,b.product_code ) h
				ON e.supplier_id=h.supplier_id AND e.product_code=h.product_code
				ORDER BY e.supplier_id
		 
	);
   return ;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;



CREATE OR REPLACE FUNCTION pu_ven_remain(in_sdate date, in_edate date, in_ventypecode character varying, in_vencode character varying, in_invtypecode character varying, in_invcode character varying)
  RETURNS SETOF record AS
$BODY$
DECLARE
    v_rec RECORD;
		end_num integer;
BEGIN
   end_num := 0;
	 --采购结算余额表
   return query   ( 
			SELECT e.*, 
				COALESCE(h.settleSumQuantity,0) as settleSumQuantity,
				COALESCE(h.settleSumMoney,0) as settleSumMoney, 
				COALESCE(f.startSumQuantity,0)-COALESCE(g.startSettleSumQuantity,0) as startSumQuantity, 
				COALESCE(f.startSumMoney,0)-COALESCE(g.startSettleSumMoney,0) as startSumMoney,
				COALESCE(g.startSettleSumQuantity,0) as startSettleSumQuantity, 
				COALESCE(g.startSettleSumMoney,0) as startSettleSumMoney,
				COALESCE(f.startSumQuantity,0)-COALESCE(g.startSettleSumQuantity,0)+e.sumQuantity-COALESCE(h.settleSumQuantity,0) as endSumQuantity, 
				COALESCE(f.startSumMoney,0)-COALESCE(g.startSettleSumMoney,0)+e.sumMoney-COALESCE(h.settleSumMoney,0) as endSumMoney
			FROM 
				--本期入库
				(SELECT a.supplier_id,c.supplie_name,b.product_code,d.product_name,
						sum(b.quantity) as sumQuantity,sum(b.money) as sumMoney
					FROM rd_record a, rd_records b, ba_suppliers c, ba_product d
					WHERE a.rd_no=b.rd_no AND is_handle=true
						AND (a.vouch_type='01' OR a.vouch_type='14')
						AND a.supplier_id=c.supplie_code AND b.product_code=d.product_code
						AND a.bus_date>=in_sdate AND a.bus_date<=in_edate
						AND c.supplie_type LIKE in_ventypecode AND a.supplier_id LIKE in_vencode
						AND b.product_code LIKE in_invcode AND d.type_id LIKE in_invtypecode
					GROUP BY a.supplier_id,b.product_code,d.product_name,c.supplie_name ) e
				LEFT JOIN 
					(SELECT a.supplier_id, b.product_code, 
						sum(b.quantity) as startSumQuantity, sum(b.money) as startSumMoney
						FROM rd_record a, rd_records b
						WHERE a.rd_no=b.rd_no AND is_handle=true
						AND (a.vouch_type='01' OR a.vouch_type='14')
						AND a.bus_date<in_sdate 
						GROUP BY a.supplier_id,b.product_code ) f
				ON e.supplier_id=f.supplier_id AND e.product_code=f.product_code
				LEFT JOIN 
					(SELECT a.supplier_id, b.product_code, 
						sum(b.quantity) as startSettleSumQuantity, sum(b.quantity*c.unit_price) as startSettleSumMoney
						FROM pu_settle_vouch a, pu_settle_vouchs b, rd_records c
						WHERE a.no=b.settle_no AND is_handle=true
						AND b.rd_no=c.rd_no AND b.product_code=c.product_code
						AND a.settle_date<in_sdate 
						GROUP BY a.supplier_id,b.product_code ) g
				ON e.supplier_id=g.supplier_id AND e.product_code=g.product_code
				--本期结算
				LEFT JOIN 
					(SELECT a.supplier_id, b.product_code, 
						sum(b.quantity) as settleSumQuantity, sum(b.quantity*c.unit_price) as settleSumMoney
						FROM pu_settle_vouch a, pu_settle_vouchs b, rd_records c
						WHERE a.no=b.settle_no AND is_handle=true
						AND b.rd_no=c.rd_no AND b.product_code=c.product_code
						AND a.settle_date>=in_sdate AND a.settle_date<=in_edate
						GROUP BY a.supplier_id,b.product_code ) h
				ON e.supplier_id=h.supplier_id AND e.product_code=h.product_code
				ORDER BY e.supplier_id
		 
	);
   return ;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;


CREATE OR REPLACE FUNCTION sa_con_settle_remain(in_sdate date, in_edate date, in_custypecode character varying, in_cuscode character varying, in_invtypecode character varying, in_invcode character varying)
  RETURNS SETOF record AS
$BODY$
DECLARE
    v_rec RECORD;
		end_num integer;
BEGIN
   end_num := 0;
	 --销售结算余额表
   return query   ( 
			SELECT e.*, 
				COALESCE(h.settleSumQuantity,0) as settleSumQuantity,
				COALESCE(h.settleSumMoney,0) as settleSumMoney,
				COALESCE(h.settleSumAmount,0) as settleSumAmount,
				COALESCE(f.startSumQuantity,0)-COALESCE(g.startSettleSumQuantity,0) as startSumQuantity, 
				COALESCE(f.startSumMoney,0)-COALESCE(g.startSettleSumMoney,0) as startSumMoney,
				COALESCE(g.startSettleSumQuantity,0) as startSettleSumQuantity, 
				COALESCE(g.startSettleSumMoney,0) as startSettleSumMoney,
				COALESCE(f.startSumQuantity,0)-COALESCE(g.startSettleSumQuantity,0)+e.sumQuantity-COALESCE(h.settleSumQuantity,0) as endSumQuantity, 
				COALESCE(f.startSumMoney,0)-COALESCE(g.startSettleSumMoney,0)+e.sumMoney-COALESCE(h.settleSumMoney,0) as endSumMoney
			FROM 
				--本期出库
				(SELECT a.cus_code,c.cus_name,b.product_code,d.product_name,
						sum(b.quantity) as sumQuantity,sum(b.money) as sumMoney
					FROM rd_record a, rd_records b, ba_customer c, ba_product d
					WHERE a.rd_no=b.rd_no AND is_handle=true
						AND (a.vouch_type='11' OR a.vouch_type='12')
						AND a.cus_code=c.cus_code AND b.product_code=d.product_code
						AND a.bus_date>=in_sdate AND a.bus_date<=in_edate
						AND c.cus_type LIKE in_cusTypeCode AND a.cus_code LIKE in_cusCode
						AND b.product_code LIKE in_invcode AND d.type_id LIKE in_invTypeCode
					GROUP BY a.cus_code,b.product_code,d.product_name,c.cus_name ) e
				--上期结余
				LEFT JOIN 
					(SELECT a.cus_code, b.product_code, 
						sum(b.quantity) as startSumQuantity, sum(b.money) as startSumMoney
						FROM rd_record a, rd_records b
						WHERE a.rd_no=b.rd_no AND is_handle=true
						AND (a.vouch_type='11' OR a.vouch_type='12')
						AND a.bus_date<in_sdate 
						GROUP BY a.cus_code,b.product_code ) f
				ON e.cus_code=f.cus_code AND e.product_code=f.product_code
				LEFT JOIN 
					(SELECT a.cus_code, b.product_code, 
						sum(b.quantity) as startSettleSumQuantity, sum(b.quantity*c.unit_price) as startSettleSumMoney
						FROM sa_settle_vouch a, sa_settle_vouchs b, rd_records c
						WHERE a.no=b.settle_no AND is_handle=true AND ( bus_type='03' OR bus_type='04' )
						AND b.rd_no=c.rd_no AND b.product_code=c.product_code
						AND a.settle_date<in_sdate 
						GROUP BY a.cus_code,b.product_code ) g
				ON e.cus_code=g.cus_code AND e.product_code=g.product_code
				--本期结算
				LEFT JOIN 
					(SELECT a.cus_code, b.product_code, 
						sum(b.quantity) as settleSumQuantity, sum(b.quantity*c.unit_price) as settleSumMoney,
						sum(b.amount) as settleSumAmount
						FROM sa_settle_vouch a, sa_settle_vouchs b, rd_records c
						WHERE a.no=b.settle_no AND is_handle=true AND ( bus_type='03' OR bus_type='04' )
						AND b.rd_no=c.rd_no AND b.product_code=c.product_code
						AND a.settle_date>=in_sdate AND a.settle_date<=in_edate
						GROUP BY a.cus_code,b.product_code ) h
				ON e.cus_code=h.cus_code AND e.product_code=h.product_code
				ORDER BY e.cus_code
		 
	);
   return ;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;


CREATE OR REPLACE FUNCTION sa_settle_remain(in_sdate date, in_edate date, in_custypecode character varying, in_cuscode character varying, in_invtypecode character varying, in_invcode character varying)
  RETURNS SETOF record AS
$BODY$
DECLARE
    v_rec RECORD;
		end_num integer;
BEGIN
   end_num := 0;
	 --销售结算余额表
   return query   ( 
			SELECT e.*, 
				COALESCE(h.settleSumQuantity,0) as settleSumQuantity,
				COALESCE(h.settleSumMoney,0) as settleSumMoney,
				COALESCE(h.settleSumAmount,0) as settleSumAmount,
				COALESCE(f.startSumQuantity,0)-COALESCE(g.startSettleSumQuantity,0) as startSumQuantity, 
				COALESCE(f.startSumMoney,0)-COALESCE(g.startSettleSumMoney,0) as startSumMoney,
				COALESCE(g.startSettleSumQuantity,0) as startSettleSumQuantity, 
				COALESCE(g.startSettleSumMoney,0) as startSettleSumMoney,
				COALESCE(f.startSumQuantity,0)-COALESCE(g.startSettleSumQuantity,0)+e.sumQuantity-COALESCE(h.settleSumQuantity,0) as endSumQuantity, 
				COALESCE(f.startSumMoney,0)-COALESCE(g.startSettleSumMoney,0)+e.sumMoney-COALESCE(h.settleSumMoney,0) as endSumMoney
			FROM 
				--本期出库
				(SELECT a.cus_code,c.cus_name,b.product_code,d.product_name,
						sum(b.quantity) as sumQuantity,sum(b.money) as sumMoney
					FROM rd_record a, rd_records b, ba_customer c, ba_product d
					WHERE a.rd_no=b.rd_no AND is_handle=true
						AND (a.vouch_type='02' OR a.vouch_type='15')
						AND a.cus_code=c.cus_code AND b.product_code=d.product_code
						AND a.bus_date>=in_sdate AND a.bus_date<=in_edate
						AND c.cus_type LIKE in_cusTypeCode AND a.cus_code LIKE in_cusCode
						AND b.product_code LIKE in_invcode AND d.type_id LIKE in_invTypeCode
					GROUP BY a.cus_code,b.product_code,d.product_name,c.cus_name ) e
				--上期结余
				LEFT JOIN 
					(SELECT a.cus_code, b.product_code, 
						sum(b.quantity) as startSumQuantity, sum(b.money) as startSumMoney
						FROM rd_record a, rd_records b
						WHERE a.rd_no=b.rd_no AND is_handle=true
						AND (a.vouch_type='02' OR a.vouch_type='15')
						AND a.bus_date<in_sdate 
						GROUP BY a.cus_code,b.product_code ) f
				ON e.cus_code=f.cus_code AND e.product_code=f.product_code
				LEFT JOIN 
					(SELECT a.cus_code, b.product_code, 
						sum(b.quantity) as startSettleSumQuantity, sum(b.quantity*c.unit_price) as startSettleSumMoney
						FROM sa_settle_vouch a, sa_settle_vouchs b, rd_records c
						WHERE a.no=b.settle_no AND is_handle=true
						AND b.rd_no=c.rd_no AND b.product_code=c.product_code
						AND a.settle_date<in_sdate 
						GROUP BY a.cus_code,b.product_code ) g
				ON e.cus_code=g.cus_code AND e.product_code=g.product_code
				--本期结算
				LEFT JOIN 
					(SELECT a.cus_code, b.product_code, 
						sum(b.quantity) as settleSumQuantity, sum(b.quantity*c.unit_price) as settleSumMoney,
						sum(b.amount) as settleSumAmount
						FROM sa_settle_vouch a, sa_settle_vouchs b, rd_records c
						WHERE a.no=b.settle_no AND is_handle=true
						AND b.rd_no=c.rd_no AND b.product_code=c.product_code
						AND a.settle_date>=in_sdate AND a.settle_date<=in_edate
						GROUP BY a.cus_code,b.product_code ) h
				ON e.cus_code=h.cus_code AND e.product_code=h.product_code
				ORDER BY e.cus_code
		 
	);
   return ;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;


CREATE OR REPLACE FUNCTION st_inv_account(in_sdate date, in_edate date, in_whcode character varying, in_invcode character varying, in_ishandle boolean)
  RETURNS SETOF record AS
$BODY$
DECLARE
	v_rec RECORD;
	strat_sum numeric; --期初数量
	i_qty_sum numeric; --期初累记入库数量
	o_qty_sum numeric; --期初累记出库数量
	end_sum numeric;   --期未数量
BEGIN
	-- 商品台帐
	end_sum := 0;
	strat_sum := 0;
	i_qty_sum := 0;
	o_qty_sum := 0;
	drop table if exists temp_st_account;
	SELECT sum(quantity) into i_qty_sum
		FROM rd_record a, rd_records b 
		where a.rd_no=b.rd_no AND a.rd_flag=1 AND b.product_code=in_invcode AND a.wh_code=in_whcode
			AND a.bus_date<in_sdate
		GROUP BY product_code;	
	SELECT sum(quantity) into o_qty_sum
		FROM rd_record a, rd_records b 
		where a.rd_no=b.rd_no AND a.rd_flag=2 AND b.product_code=in_invcode AND a.wh_code=in_whcode
			AND a.bus_date<in_sdate
		GROUP BY product_code;
	IF i_qty_sum IS NULL THEN
		i_qty_sum := 0;
	END IF;
	IF o_qty_sum IS NULL THEN
		o_qty_sum := 0;
	END IF;
	strat_sum = i_qty_sum - o_qty_sum;
	CREATE TEMP TABLE temp_st_account AS SELECT row_number() OVER(ORDER BY c.bus_date,c.rd_flag,c.mx_id) as row_num,d.wh_name,
	c.mx_id,c.bus_date,c.rd_no,c.bus_type,c.wh_code,c.cus_code,c.product_code, c.in_q, c.out_q,0 as e_sum
	FROM (
		SELECT a.id as mx_id,a.rd_flag,a.bus_date,a.rd_no,a.bus_type,a.wh_code,a.cus_code,b.product_code, b.quantity as in_q, 0 as out_q
		FROM rd_record a, rd_records b 
		where a.rd_no=b.rd_no AND a.rd_flag=1 AND a.is_handle=true
			AND b.product_code=in_invcode AND a.wh_code=in_whcode
			AND a.bus_date>=in_sdate AND a.bus_date<=in_edate 
	union 
		SELECT a.id as mx_id,a.rd_flag,a.bus_date,a.rd_no,a.bus_type,a.wh_code,a.cus_code,b.product_code, 0 as in_q, b.quantity as out_q
		FROM rd_record a, rd_records b 
		where a.rd_no=b.rd_no AND a.rd_flag=2 AND a.is_handle=true
			AND b.product_code=in_invcode AND a.wh_code=in_whcode
			AND a.bus_date>=in_sdate AND a.bus_date<=in_edate 
	) c, ba_ware_house d 
	where c.wh_code=d.wh_code ORDER BY c.bus_date,c.rd_flag,c.mx_id ASC;
	
	UPDATE temp_st_account SET e_sum=( SELECT strat_sum + sum(in_q)-sum(out_q) FROM temp_st_account a 
		WHERE a.row_num<=temp_st_account.row_num GROUP BY product_code );
	
	return query  (SELECT a.*,b.product_name FROM temp_st_account a,ba_product b WHERE a.product_code=b.product_code ) ;
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;


CREATE OR REPLACE FUNCTION st_journal_account(in_sdate date, in_edate date, in_whcode character varying, in_type character varying, in_invcode character varying, in_ishandle boolean)
  RETURNS SETOF record AS
$BODY$
DECLARE
	v_rec RECORD;
	
BEGIN
  --出入库流水帐
	return query  (
	SELECT c.*, d.wh_name, e.product_name 
	FROM (
		SELECT a.id as mx_id,a.bus_date,a.rd_no,a.bus_no,a.bus_type,a.wh_code,a.cus_code,b.product_code, b.product_style,
		a.handler,a.is_handle, a.audit_time, a.created_by, a.creater,
		b.quantity as in_q, b.unit_price as in_price, b.money as in_money , 0 as out_q , 0 as out_price, 0 as out_money
		FROM rd_record a, rd_records b 
		where a.rd_no=b.rd_no AND a.rd_flag=1 
			AND b.product_code LIKE in_invcode AND a.wh_code LIKE in_whcode
			
			AND a.bus_date>=in_sdate AND a.bus_date<=in_edate 
	UNION 
		SELECT a.id as mx_id,a.bus_date,a.rd_no,a.bus_no,a.bus_type,a.wh_code,a.cus_code,b.product_code, b.product_style,
		a.handler,a.is_handle, a.audit_time, a.created_by, a.creater,
		0 as in_q, 0 as in_price ,0 as in_money, b.quantity as out_q, b.unit_price as out_price, b.money as out_money 
		FROM rd_record a, rd_records b 
		where a.rd_no=b.rd_no AND a.rd_flag=2
			AND b.product_code LIKE in_invcode AND a.wh_code LIKE in_whcode
			AND a.bus_date>=in_sdate AND a.bus_date<=in_edate 
	) c, ba_ware_house d, ba_product e 
	where c.wh_code=d.wh_code AND c.product_code=e.product_code AND e.type_id LIKE in_type 
	ORDER BY c.bus_date,c.mx_id ASC );
	
	
	
END;
$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100
  ROWS 1000;