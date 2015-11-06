/*==============================================================*/
/* Table: ap_close_bill                                         */
/*==============================================================*/
create table ap_close_bill (
   id                   SERIAL not null,
   ap_no                VARCHAR(30)          not null,
   bus_date             DATE                 null,
   bus_flag             INT2                 null,
   vouch_type           VARCHAR(30)          null,
   bus_code             VARCHAR(30)          null,
   dep_code             VARCHAR(20)          null,
   person_code          VARCHAR(20)          null,
   settle_code          VARCHAR(30)          null,
   amount               DECIMAL              null,
   digest               VARCHAR(230)         null,
   sum                  DECIMAL              null,
   km_code              VARCHAR(30)          null,
   bank_account         VARCHAR(50)          null,
   bank_name            VARCHAR(100)         null,
   contract_id          VARCHAR(30)          null,
   contract_name        VARCHAR(100)         null,
   is_voucher           BOOL                 null,
   handler              VARCHAR(20)          null,
   is_handle            BOOL                 null,
   audit_time           TIMESTAMP            null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   memo                 VARCHAR(200)         null,
   constraint PK_AP_CLOSE_BILL primary key (id),
   constraint AK_KEY_NO_AP_CLOSE unique (ap_no)
);

/*==============================================================*/
/* Table: ap_close_bills                                        */
/*==============================================================*/
create table ap_close_bills (
   id                   SERIAL not null,
   ap_no                VARCHAR(30)          not null,
   order_no             VARCHAR(30)          null,
   bus_no               VARCHAR(30)          null,
   bus_vouch            VARCHAR(30)          null,
   funds_type           VARCHAR(30)          null,
   km_code              VARCHAR(30)          not null,
   digest               VARCHAR(230)         null,
   amount               DECIMAL              null,
   sum                  DECIMAL              null,
   item_code            VARCHAR(30)          null,
   ap_bill              VARCHAR(50)          null,
   constraint PK_AP_CLOSE_BILLS primary key (id)
);

/*==============================================================*/
/* Table: ap_vouch                                              */
/*==============================================================*/
create table ap_vouch (
   id                   SERIAL not null,
   ap_no                VARCHAR(30)          not null,
   bus_date             DATE                 null,
   bus_flag             INT2                 null,
   vouch_type           VARCHAR(30)          null,
   bus_code             VARCHAR(30)          null,
   dep_code             VARCHAR(20)          null,
   person_code          VARCHAR(20)          null,
   amount               DECIMAL              null,
   digest               VARCHAR(230)         null,
   sum                  DECIMAL              null,
   km_code              VARCHAR(30)          null,
   contract_id          VARCHAR(30)          null,
   contract_name        VARCHAR(100)         null,
   is_voucher           BOOL                 null,
   handler              VARCHAR(20)          null,
   is_handle            BOOL                 null,
   audit_time           TIMESTAMP            null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   memo                 VARCHAR(200)         null,
   constraint PK_AP_VOUCH primary key (id),
   constraint AK_KEY_2_AP_VOUCH unique (ap_no)
);

/*==============================================================*/
/* Table: ap_vouchs                                             */
/*==============================================================*/
create table ap_vouchs (
   id                   SERIAL not null,
   ap_no                VARCHAR(30)          not null,
   order_no             VARCHAR(30)          null,
   bus_no               VARCHAR(30)          null,
   bus_vouch            VARCHAR(30)          null,
   funds_type           VARCHAR(30)          null,
   km_code              VARCHAR(30)          not null,
   digest               VARCHAR(230)         null,
   amount               DECIMAL              null,
   sum                  DECIMAL              null,
   item_code            VARCHAR(30)          null,
   ap_bill              VARCHAR(50)          null,
   constraint PK_AP_VOUCHS primary key (id)
);

/*==============================================================*/
/* Table: ba_ap_type                                            */
/*==============================================================*/
create table ba_ap_type (
   type_code            VARCHAR(30)          not null,
   type_name            VARCHAR(30)          not null,
   flag                 INT2                 null,
   constraint PK_BA_AP_TYPE primary key (type_code)
);

/*==============================================================*/
/* Table: ba_cause                                              */
/*==============================================================*/
create table ba_cause (
   id                   INT4                 not null,
   taste_name           VARCHAR(20)          not null,
   is_discounts         BOOL                 null,
   is_back              BOOL                 null,
   constraint PK_BA_CAUSE primary key (id)
);

/*==============================================================*/
/* Table: ba_code_scheme                                        */
/*==============================================================*/
create table ba_code_scheme (
   id                   NUMERIC              not null,
   name                 VARCHAR(100)         not null,
   length               INT2                 not null,
   level                INT2                 not null,
   level_one            INT2                 null,
   level_two            INT2                 null,
   level_three          INT2                 null,
   level_four           INT2                 null,
   level_five           INT2                 null,
   constraint PK_BA_CODE_SCHEME primary key (id)
);

/*==============================================================*/
/* Table: ba_customer                                           */
/*==============================================================*/
create table ba_customer (
   id                   SERIAL not null,
   cus_code             VARCHAR(50)          not null,
   cus_name             VARCHAR(50)          not null,
   cus_alias            VARCHAR(50)          not null,
   cus_type             VARCHAR(50)          null,
   pinyin_code          VARCHAR(50)          null,
   area_city            VARCHAR(50)          null,
   trade                VARCHAR(100)         null,
   address              VARCHAR(200)         null,
   post                 VARCHAR(50)          null,
   cus_reg_code         VARCHAR(100)         null,
   cus_bank             VARCHAR(100)         null,
   cus_account          VARCHAR(100)         null,
   dev_date             DATE                 null,
   corporate            VARCHAR(50)          null,
   email                VARCHAR(100)         null,
   contacts             VARCHAR(50)          null,
   tel                  VARCHAR(50)          null,
   fax                  VARCHAR(50)          null,
   phone                VARCHAR(50)          null,
   cus_address          VARCHAR(200)         null,
   cus_person           VARCHAR(50)          null,
   dep_code             VARCHAR(30)          null,
   is_credit            BOOL                 null,
   cus_cre_grade        VARCHAR(50)          null,
   cus_cre_line         DECIMAL(10)          null,
   cus_cre_date         INT8                 null,
   is_shop              BOOL                 null,
   licence_sdate        DATE                 null,
   licence_edate        DATE                 null,
   memo                 VARCHAR(200)         null,
   status               INT2                 not null default 0,
   cus_define1          VARCHAR(200)         null,
   cus_define2          VARCHAR(200)         null,
   cus_define3          VARCHAR(200)         null,
   constraint PK_BA_CUSTOMER primary key (id),
   constraint AK_KEY_2_BA_CUSTO unique (cus_code)
);

/*==============================================================*/
/* Table: ba_customer_type                                      */
/*==============================================================*/
create table ba_customer_type (
   type_id              VARCHAR(18)          not null,
   type_name            VARCHAR(50)          not null,
   type_end             BOOL                 null,
   type_grade           INT2                 null,
   type_superior        VARCHAR(18)          null,
   explian              VARCHAR(200)         null,
   memo                 VARCHAR(200)         null,
   constraint PK_BA_CUSTOMER_TYPE primary key (type_id)
);

/*==============================================================*/
/* Table: ba_department                                         */
/*==============================================================*/
create table ba_department (
   dep_id               VARCHAR(18)          not null,
   dep_name             VARCHAR(50)          not null,
   dep_end              BOOL                 null,
   dep_grade            INT2                 null,
   dep_superior         VARCHAR(18)          null,
   dep_person           VARCHAR(20)          null,
   dep_tel              VARCHAR(20)          null,
   dep_addr             VARCHAR(200)         null,
   memo                 VARCHAR(200)         null,
   constraint PK_BA_DEPARTMENT primary key (dep_id)
);

/*==============================================================*/
/* Table: ba_dinner                                             */
/*==============================================================*/
create table ba_dinner (
   id                   SERIAL not null,
   dinner_id            VARCHAR(10)          not null,
   dinner_name          VARCHAR(20)          null,
   area_id              INT8                 null,
   dinner_type          VARCHAR(20)          null,
   number               INT8                 null,
   is_service           BOOL                 null,
   lost_consumption     FLOAT8               null,
   memo                 VARCHAR(250)         null,
   constraint PK_BA_DINNER primary key (id),
   constraint AK_KEY_2_BA_DINNE unique (dinner_id)
);

/*==============================================================*/
/* Table: ba_dinner_area                                        */
/*==============================================================*/
create table ba_dinner_area (
   area_id              SERIAL not null,
   area_name            VARCHAR(100)         null,
   area_explian         VARCHAR(200)         null,
   constraint PK_BA_DINNER_AREA primary key (area_id)
);

/*==============================================================*/
/* Table: ba_discount                                           */
/*==============================================================*/
create table ba_discount (
   ID                   INT4                 not null,
   name                 VARCHAR(20)          null,
   discount_type        INT2                 null,
   discount             DECIMAL              null,
   status               INT2                 null,
   level                INT2                 null default 1,
   condition            VARCHAR(100)         null,
   memo                 VARCHAR(250)         null,
   constraint PK_BA_DISCOUNT primary key (ID)
);

/*==============================================================*/
/* Table: ba_discount_type                                      */
/*==============================================================*/
create table ba_discount_type (
   ID                   INT2                 not null,
   discount_type        VARCHAR(100)         null,
   explanation          VARCHAR(100)         null,
   constraint PK_BA_DISCOUNT_TYPE primary key (ID)
);

/*==============================================================*/
/* Table: ba_dishes                                             */
/*==============================================================*/
create table ba_dishes (
   dishes_id            SERIAL not null,
   dishes_code          VARCHAR(20)          not null,
   dishes_name          VARCHAR(50)          not null,
   pinyin_code          VARCHAR(50)          null,
   assisted_code        VARCHAR(50)          null,
   en_name              VARCHAR(50)          null,
   style                VARCHAR(50)          null,
   unit                 VARCHAR(20)          null,
   type_id              VARCHAR(18)          null,
   price1               DECIMAL              null,
   price2               DECIMAL              null,
   price3               DECIMAL              null,
   m_price1             DECIMAL              null,
   m_price2             DECIMAL              null,
   m_price3             DECIMAL              null,
   status               INT2                 null,
   low_discount         DECIMAL              null default 0,
   is_temp_dishes       BOOL                 null,
   is_weighing_conf     BOOL                 null,
   is_disc              BOOL                 null,
   is_current_prices    BOOL                 null,
   is_set               BOOL                 null,
   is_down_pad          BOOL                 null,
   is_piece_dishes      BOOL                 null,
   is_marketing         BOOL                 null,
   eat_type             VARCHAR(50)          null,
   picture1             VARCHAR(150)         null,
   picture2             VARCHAR(150)         null,
   picture3             VARCHAR(150)         null,
   constraint PK_BA_DISHES primary key (dishes_id),
   constraint AK_KEY_2_BA_DISHE unique (dishes_code)
);

/*==============================================================*/
/* Index: Index_dishes_code                                     */
/*==============================================================*/
create  index Index_dishes_code on ba_dishes (
dishes_code
);

/*==============================================================*/
/* Index: Index_dishes_name                                     */
/*==============================================================*/
create  index Index_dishes_name on ba_dishes (
dishes_name
);

/*==============================================================*/
/* Table: ba_employee                                           */
/*==============================================================*/
create table ba_employee (
   emp_id               SERIAL not null,
   emp_code             VARCHAR(20)          not null,
   emp_name             VARCHAR(20)          not null,
   dep_id               VARCHAR(18)          null,
   emp_attr             VARCHAR(50)          null,
   entry_date           DATE                 null,
   memo                 VARCHAR(200)         null,
   created_by           NUMERIC              null,
   created              TIMESTAMP            null,
   sex                  VARCHAR(10)          null,
   height               VARCHAR(10)          null,
   weight               VARCHAR(10)          null,
   nation               VARCHAR(50)          null,
   hometown             VARCHAR(50)          null,
   birth                DATE                 null,
   educational          VARCHAR(50)          null,
   graduation_date      DATE                 null,
   graduation_shcool    VARCHAR(150)         null,
   phone                VARCHAR(50)          null,
   card_number          VARCHAR(50)          null,
   addr                 VARCHAR(150)         null,
   zip                  VARCHAR(50)          null,
   residence_addr       VARCHAR(150)         null,
   tel                  VARCHAR(50)          null,
   guarantor            VARCHAR(50)          null,
   guarantor_tel        VARCHAR(50)          null,
   guarantor_number     VARCHAR(50)          null,
   guarantor_addr       VARCHAR(150)         null,
   guarantor_relation   VARCHAR(50)          null,
   status               INT2                 not null default 0,
   constraint PK_BA_EMPLOYEE primary key (emp_id),
   constraint AK_KEY_2_BA_EMPLO unique (emp_code)
);

/*==============================================================*/
/* Table: ba_employee_info                                      */
/*==============================================================*/
create table ba_employee_info (
   emp_code             VARCHAR(20)          not null,
   sex                  VARCHAR(10)          null,
   height               VARCHAR(10)          null,
   weight               VARCHAR(10)          null,
   nation               VARCHAR(50)          null,
   hometown             VARCHAR(50)          null,
   birth                DATE                 null,
   educational          VARCHAR(50)          null,
   graduation_date      DATE                 null,
   graduation_shcool    VARCHAR(150)         null,
   phone                VARCHAR(50)          null,
   card_number          VARCHAR(50)          null,
   addr                 VARCHAR(150)         null,
   zip                  VARCHAR(50)          null,
   residence_addr       VARCHAR(150)         null,
   tel                  VARCHAR(50)          null,
   guarantor            VARCHAR(50)          null,
   guarantor_tel        VARCHAR(50)          null,
   guarantor_number     VARCHAR(50)          null,
   guarantor_addr       VARCHAR(150)         null,
   guarantor_relation   VARCHAR(50)          null,
   constraint PK_BA_EMPLOYEE_INFO primary key (emp_code)
);

/*==============================================================*/
/* Table: ba_kcode                                              */
/*==============================================================*/
create table ba_kcode (
   km_code              VARCHAR(30)          not null,
   km_name              VARCHAR(150)         not null,
   grade                INT2                 null,
   code                 VARCHAR(30)          null,
   is_end               BOOL                 null,
   property             INT2                 null,
   km_explain           VARCHAR(250)         null,
   is_cus               BOOL                 null,
   is_sup               BOOL                 null,
   is_cash              BOOL                 null,
   is_bank              BOOL                 null,
   constraint PK_BA_KCODE primary key (km_code)
);

/*==============================================================*/
/* Table: ba_market_type                                        */
/*==============================================================*/
create table ba_market_type (
   market_type_id       SERIAL not null,
   market_type_name     VARCHAR(20)          not null,
   market_type_start    VARCHAR(20)          null,
   market_type_alia     VARCHAR(100)         null,
   memo                 VARCHAR(200)         null,
   constraint PK_BA_MARKET_TYPE primary key (market_type_id, market_type_name)
);

/*==============================================================*/
/* Table: ba_position                                           */
/*==============================================================*/
create table ba_position (
   position_code        VARCHAR(10)          not null,
   position_name        VARCHAR(20)          not null,
   wh_code              VARCHAR(10)          null,
   position_unit        VARCHAR(20)          null,
   top_sum              INT8                 null,
   position_desc        VARCHAR(200)         null,
   position_area        VARCHAR(20)          null,
   position_level       INT8                 null,
   status               INT2                 null,
   memo                 VARCHAR(200)         null,
   constraint PK_BA_POSITION primary key (position_code)
);

/*==============================================================*/
/* Table: ba_posset                                             */
/*==============================================================*/
create table ba_posset (
   id                   VARCHAR(3)           not null,
   name                 VARCHAR(20)          null,
   value                VARCHAR(30)          null,
   caption              VARCHAR(30)          null,
   yes_no               BOOL                 null,
   memo                 VARCHAR(200)         null,
   constraint PK_BA_POSSET primary key (id)
);

/*==============================================================*/
/* Table: ba_product                                            */
/*==============================================================*/
create table ba_product (
   id                   SERIAL not null,
   product_name         VARCHAR(50)          not null,
   product_code         VARCHAR(20)          not null,
   product_no           VARCHAR(20)          null,
   pinyin_code          VARCHAR(25)          null,
   en_name              VARCHAR(50)          null,
   assisted_code        VARCHAR(50)          null,
   style                VARCHAR(20)          null,
   unit                 VARCHAR(20)          null,
   type_id              VARCHAR(20)          null,
   supplier_id          NUMERIC              null,
   wh_code              VARCHAR(10)          null,
   position_code        VARCHAR(10)          null,
   is_raw               BOOL                 null,
   is_sale              BOOL                 null,
   is_purchase          BOOL                 null,
   is_ms_imei           BOOL                 null,
   is_comsume           BOOL                 null,
   purchase_unit        VARCHAR(20)          null,
   stock_unit           VARCHAR(20)          null,
   pu_st_unit           INT2                 null,
   st_do_unit           INT2                 null,
   dose_unit            VARCHAR(20)          null,
   sale_unit            VARCHAR(20)          null,
   is_pos_purchase      BOOL                 null,
   is_pos_down          BOOL                 null,
   is_sale_consumption  BOOL                 null,
   is_weighing_conf     BOOL                 null,
   low_sum              INT8                 null,
   top_sum              INT8                 null,
   pu_price             DECIMAL              null,
   price1               DECIMAL              null,
   price2               DECIMAL              null,
   price3               DECIMAL              null,
   m_price1             DECIMAL              null,
   m_price2             DECIMAL              null,
   m_price3             DECIMAL              null,
   low_discount         DECIMAL              null default 0,
   is_temp_dishes       BOOL                 null,
   is_disc              BOOL                 null,
   is_current_prices    BOOL                 null,
   is_set               BOOL                 null,
   is_down_pad          BOOL                 null,
   is_piece_dishes      BOOL                 null,
   is_marketing         BOOL                 null,
   is_imei              BOOL                 null,
   eat_type             VARCHAR(50)          null,
   picture1             VARCHAR(150)         null,
   picture2             VARCHAR(150)         null,
   picture3             VARCHAR(150)         null,
   created_by           NUMERIC              null,
   created              TIMESTAMP            null,
   status               INT2                 null,
   memo                 VARCHAR(200)         null,
   constraint PK_BA_PRODUCT primary key (id),
   constraint AK_KEY_2_BA_PRODU unique (product_code)
);

/*==============================================================*/
/* Table: ba_product_type                                       */
/*==============================================================*/
create table ba_product_type (
   type_id              VARCHAR(18)          not null,
   type_name            VARCHAR(50)          not null,
   type_end             BOOL                 null,
   type_grade           INT2                 null,
   type_superior        VARCHAR(18)          null,
   explian              VARCHAR(200)         null,
   is_dishes            BOOL                 not null,
   memo                 VARCHAR(200)         null,
   is_disc              BOOL                 null default true,
   low_discount         DECIMAL              null default 0,
   constraint PK_BA_PRODUCT_TYPE primary key (type_id)
);

/*==============================================================*/
/* Table: ba_settle_type                                        */
/*==============================================================*/
create table ba_settle_type (
   id                   SERIAL not null,
   settle_name          VARCHAR(20)          not null,
   settle_nature        VARCHAR(20)          null,
   settle_caption       VARCHAR(100)         null,
   constraint PK_BA_SETTLE_TYPE primary key (id)
);

/*==============================================================*/
/* Table: ba_supplie_type                                       */
/*==============================================================*/
create table ba_supplie_type (
   type_id              VARCHAR(18)          not null,
   type_name            VARCHAR(50)          not null,
   type_end             BOOL                 null,
   type_grade           INT2                 null,
   type_superior        VARCHAR(18)          null,
   explian              VARCHAR(200)         null,
   memo                 VARCHAR(200)         null,
   constraint PK_BA_SUPPLIE_TYPE primary key (type_id)
);

/*==============================================================*/
/* Table: ba_suppliers                                          */
/*==============================================================*/
create table ba_suppliers (
   supplie_id           SERIAL not null,
   supplie_code         VARCHAR(30)          not null,
   supplie_name         VARCHAR(50)          not null,
   supplie_explian      VARCHAR(200)         null,
   supplie_type         VARCHAR(200)         null,
   addr                 VARCHAR(200)         null,
   linkman              VARCHAR(20)          null,
   link_func            VARCHAR(50)          null,
   link_phone           VARCHAR(20)          null,
   tax                  VARCHAR(50)          null,
   bank                 VARCHAR(200)         null,
   bank_card            VARCHAR(20)          null,
   bank_name            VARCHAR(200)         null,
   memo                 VARCHAR(200)         null,
   created_by           NUMERIC              null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updated              TIMESTAMP            null,
   status               INT2                 null default 0,
   constraint PK_BA_SUPPLIERS primary key (supplie_id),
   constraint AK_KEY_2_BA_SUPPL unique (supplie_code)
);

/*==============================================================*/
/* Table: ba_taste                                              */
/*==============================================================*/
create table ba_taste (
   id                   SERIAL not null,
   taste_name           VARCHAR(10)          not null,
   taste_caption        VARCHAR(100)         null,
   constraint PK_BA_TASTE primary key (id)
);

/*==============================================================*/
/* Table: ba_unit                                               */
/*==============================================================*/
create table ba_unit (
   ID                   SERIAL not null,
   unit_name            VARCHAR(10)          null,
   translated_unit      VARCHAR(10)          null,
   scalings             DECIMAL              null,
   constraint PK_BA_UNIT primary key (ID)
);

/*==============================================================*/
/* Table: ba_vouch_type                                         */
/*==============================================================*/
create table ba_vouch_type (
   vouch_type           VARCHAR(10)          not null,
   vouch_name           VARCHAR(100)         not null,
   vouch_desc           VARCHAR(200)         null,
   constraint PK_BA_VOUCH_TYPE primary key (vouch_type)
);

/*==============================================================*/
/* Table: ba_ware_house                                         */
/*==============================================================*/
create table ba_ware_house (
   wh_code              VARCHAR(10)          not null,
   wh_name              VARCHAR(20)          null,
   dep_code             VARCHAR(18)          null,
   wh_addr              VARCHAR(100)         null,
   wh_tel               VARCHAR(18)          null,
   wh_person            NUMERIC              null,
   is_cargo             BOOL                 null,
   is_shop              BOOL                 null,
   memo                 VARCHAR(180)         null,
   constraint PK_BA_WARE_HOUSE primary key (wh_code)
);

/*==============================================================*/
/* Table: cm_balance                                            */
/*==============================================================*/
create table cm_balance (
   ID                   SERIAL not null,
   member_key           VARCHAR(100)         not null,
   card_key             VARCHAR(100)         not null,
   money                DECIMAL              not null,
   safe_key             VARCHAR(100)         null,
   created_by           NUMERIC              null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updated              TIMESTAMP            null,
   memo                 VARCHAR(200)         null,
   constraint PK_CM_BALANCE primary key (ID)
);

/*==============================================================*/
/* Table: cm_card_type                                          */
/*==============================================================*/
create table cm_card_type (
   card_type_id         SERIAL not null,
   card_type_name       VARCHAR(50)          null,
   is_recharge          BOOL                 null,
   shipping_type        VARCHAR(50)          null,
   member_special       VARCHAR(50)          null,
   memo                 VARCHAR(250)         null,
   constraint PK_CM_CARD_TYPE primary key (card_type_id)
);

/*==============================================================*/
/* Table: cm_consume_rd                                         */
/*==============================================================*/
create table cm_consume_rd (
   ID                   SERIAL not null,
   member_code          VARCHAR(20)          null,
   consume_money        DECIMAL              null,
   currency             VARCHAR(20)          null,
   settle_no            VARCHAR(30)          null,
   settle_date          DATE                 null,
   created_by           NUMERIC              null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updated              TIMESTAMP            null,
   memo                 VARCHAR(200)         null,
   constraint PK_CM_CONSUME_RD primary key (ID)
);

/*==============================================================*/
/* Table: cm_member                                             */
/*==============================================================*/
create table cm_member (
   member_id            SERIAL not null,
   member_code          VARCHAR(20)          not null,
   card_code            VARCHAR(50)          null,
   member_name          VARCHAR(50)          null,
   card_type            INT8                 null,
   birth                DATE                 null,
   phone                VARCHAR(20)          null,
   tel                  VARCHAR(20)          null,
   addr                 VARCHAR(200)         null,
   taste                VARCHAR(200)         null,
   status               INT2                 null,
   card_status          INT2                 null,
   sex                  VARCHAR(20)          null,
   provide_date         DATE                 null,
   term                 DATE                 null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   memo1                VARCHAR(200)         null,
   memo2                VARCHAR(200)         null,
   memo3                VARCHAR(200)         null,
   constraint PK_CM_MEMBER primary key (member_id, member_code)
);

/*==============================================================*/
/* Index: Index_member_code                                     */
/*==============================================================*/
create  index Index_member_code on cm_member (
member_code
);

/*==============================================================*/
/* Index: Index_card_code                                       */
/*==============================================================*/
create  index Index_card_code on cm_member (
card_code
);

/*==============================================================*/
/* Index: Index_member_name                                     */
/*==============================================================*/
create  index Index_member_name on cm_member (
member_name
);

/*==============================================================*/
/* Table: cm_recharge_rd                                        */
/*==============================================================*/
create table cm_recharge_rd (
   ID                   SERIAL not null,
   recharge_type        VARCHAR(20)          null,
   member_code          VARCHAR(30)          null,
   card_code            VARCHAR(50)          null,
   card_money           DECIMAL              null,
   recharge_money       DECIMAL              null,
   currency             VARCHAR(20)          null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   memo                 VARCHAR(200)         null,
   constraint PK_CM_RECHARGE_RD primary key (ID)
);

/*==============================================================*/
/* Table: fa_cost_accounting_way                                */
/*==============================================================*/
create table fa_cost_accounting_way (
   way_id               INT8                 not null,
   way_name             VARCHAR(200)         not null,
   way_note             VARCHAR(250)         null,
   memo                 VARCHAR(250)         null,
   status               INT4                 not null,
   constraint PK_FA_COST_ACCOUNTING_WAY primary key (way_id)
);

/*==============================================================*/
/* Table: fa_month_close                                        */
/*==============================================================*/
create table fa_month_close (
   ID                   SERIAL not null,
   year                 VARCHAR(5)           not null,
   month                VARCHAR(2)           not null,
   bus_date             DATE                 null,
   digest               VARCHAR(200)         null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   constraint PK_FA_MONTH_CLOSE primary key (ID)
);

/*==============================================================*/
/* Table: fa_subsidiary                                         */
/*==============================================================*/
create table fa_subsidiary (
   ID                   SERIAL not null,
   rd_flag              INT2                 not null,
   vouch_no             VARCHAR(30)          not null,
   vouch_type           VARCHAR(10)          null,
   batch_id             VARCHAR(20)          null,
   batch_amount         DECIMAL              null,
   bus_type             VARCHAR(10)          null,
   vouch_source         VARCHAR(50)          null,
   bus_no               VARCHAR(30)          null,
   order_no             VARCHAR(30)          null,
   dv_id                NUMERIC(30)          null,
   dv_no                VARCHAR(30)          null,
   settle_no            VARCHAR(30)          null,
   wh_code              VARCHAR(10)          null,
   dep_code             VARCHAR(20)          null,
   person_code          VARCHAR(20)          null,
   cus_code             VARCHAR(30)          null,
   sup_code             VARCHAR(30)          null,
   pt_code              VARCHAR(2)           null,
   st_code              VARCHAR(2)           null,
   bus_date             DATE                 not null,
   keep_date            DATE                 not null,
   month                INT2                 null,
   pz_id                VARCHAR(30)          null,
   pz_date              DATE                 null,
   pz_type              VARCHAR(30)          null,
   pz_digest            VARCHAR(200)         null,
   vouchs_id            NUMERIC(30)          null,
   product_code         VARCHAR(30)          null,
   in_quantity          DECIMAL              null,
   out_quantity         DECIMAL              null,
   st_quantity          DECIMAL              null,
   in_cost              DECIMAL              null,
   out_cost             DECIMAL              null,
   out_price            DECIMAL              null,
   in_money             DECIMAL              null,
   out_money            DECIMAL              null,
   st_money             DECIMAL              null,
   accounter            VARCHAR(20)          not null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   memo                 VARCHAR(250)         null,
   constraint PK_FA_SUBSIDIARY primary key (ID)
);

/*==============================================================*/
/* Table: fa_summary                                            */
/*==============================================================*/
create table fa_summary (
   ID                   SERIAL not null,
   year                 INT8                 null,
   month                INT2                 null,
   wh_code              VARCHAR(10)          null,
   dep_code             VARCHAR(20)          null,
   person_code          VARCHAR(20)          null,
   product_code         VARCHAR(30)          null,
   in_num               DECIMAL              null,
   out_num              DECIMAL              null,
   end_num              DECIMAL              null,
   in_money             DECIMAL              null,
   out_money            DECIMAL              null,
   st_money             DECIMAL              null,
   price                DECIMAL              null,
   constraint PK_FA_SUMMARY primary key (ID)
);

/*==============================================================*/
/* Table: product_structure                                     */
/*==============================================================*/
create table product_structure (
   ID                   SERIAL not null,
   psp_code             VARCHAR(20)          null,
   dep_code             VARCHAR(20)          null,
   is_expand            BOOL                 null,
   is_reckon            BOOL                 null,
   unit                 VARCHAR(20)          null,
   handler              VARCHAR(20)          null,
   audit_time           TIMESTAMP            null,
   status               INT2                 null,
   created_by           NUMERIC              null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updated              TIMESTAMP            null,
   constraint PK_PRODUCT_STRUCTURE primary key (ID),
   constraint AK_KEY_2_PRODUCT_ unique (psp_code)
);

/*==============================================================*/
/* Table: product_structures                                    */
/*==============================================================*/
create table product_structures (
   ID                   SERIAL not null,
   psp_code             VARCHAR(20)          not null,
   ps_code              VARCHAR(20)          not null,
   quantity             NUMERIC              null,
   reality_quantity     NUMERIC              null default 0,
   waste_unit           VARCHAR(20)          null,
   waste_rate           DECIMAL              null,
   chang_rate           DECIMAL              null,
   constraint PK_PRODUCT_STRUCTURES primary key (ID)
);

/*==============================================================*/
/* Table: pu_arrival_vouch                                      */
/*==============================================================*/
create table pu_arrival_vouch (
   id                   SERIAL not null,
   no                   VARCHAR(30)          not null,
   bus_date             DATE                 null,
   bus_type             VARCHAR(10)          null,
   pu_type              VARCHAR(10)          null,
   supplier_id          VARCHAR(20)          null,
   wh_code              VARCHAR(10)          null,
   dep_code             VARCHAR(20)          null,
   person_code          VARCHAR(20)          null,
   handler              VARCHAR(20)          null,
   audit_time           TIMESTAMP            null,
   is_handle            BOOL                 null,
   is_complete          BOOL                 null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   closer               VARCHAR(20)          null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   status               INT2                 null,
   memo                 VARCHAR(200)         null,
   constraint PK_PU_ARRIVAL_VOUCH primary key (id),
   constraint AK_KEY_2_PU_ARRIV unique (no)
);

/*==============================================================*/
/* Table: pu_arrival_vouchs                                     */
/*==============================================================*/
create table pu_arrival_vouchs (
   ID                   SERIAL not null,
   arrival_no           VARCHAR(30)          not null,
   order_no             VARCHAR(30)          null,
   src_no               VARCHAR(30)          null,
   supplier_id          VARCHAR(20)          null,
   product_code         VARCHAR(20)          not null,
   product_style        VARCHAR(20)          null,
   unit                 VARCHAR(20)          null,
   quantity             DECIMAL              null,
   in_quantity          DECIMAL              null,
   re_quantity          DECIMAL              null,
   price                DECIMAL              null,
   tax_price            DECIMAL              null,
   money                DECIMAL              null,
   constraint PK_PU_ARRIVAL_VOUCHS primary key (ID)
);

/*==============================================================*/
/* Table: pu_order_vouch                                        */
/*==============================================================*/
create table pu_order_vouch (
   id                   SERIAL not null,
   no                   VARCHAR(30)          not null,
   bus_date             DATE                 null,
   bus_type             VARCHAR(10)          null,
   supplier_id          VARCHAR(20)          null,
   wh_code              VARCHAR(10)          null,
   dep_code             VARCHAR(20)          null,
   demand_date          DATE                 null,
   project_date         DATE                 null,
   person_code          VARCHAR(20)          null,
   handler              VARCHAR(20)          null,
   audit_time           TIMESTAMP            null,
   is_handle            BOOL                 null,
   is_complete          BOOL                 null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   closer               VARCHAR(20)          null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   status               INT2                 null,
   memo                 VARCHAR(200)         null,
   constraint PK_PU_ORDER_VOUCH primary key (id),
   constraint AK_KEY_2_PU_ORDER unique (no)
);

/*==============================================================*/
/* Table: pu_order_vouchs                                       */
/*==============================================================*/
create table pu_order_vouchs (
   ID                   SERIAL not null,
   order_no             VARCHAR(30)          not null,
   supplier_id          VARCHAR(20)          null,
   product_code         VARCHAR(20)          not null,
   product_style        VARCHAR(20)          null,
   unit                 VARCHAR(20)          null,
   quantity             DECIMAL              null,
   in_quantity          DECIMAL              null default 0,
   re_quantity          DECIMAL              null default 0,
   is_complete          BOOL                 null,
   price                DECIMAL              null,
   tax_price            DECIMAL              null,
   money                DECIMAL              null,
   toq                  INT8                 null,
   constraint PK_PU_ORDER_VOUCHS primary key (ID)
);

/*==============================================================*/
/* Table: pu_settle_vouch                                       */
/*==============================================================*/
create table pu_settle_vouch (
   id                   SERIAL not null,
   no                   VARCHAR(30)          not null,
   pt_code              VARCHAR(10)          null,
   order_no             VARCHAR(30)          null,
   rd_no                VARCHAR(30)          null,
   settle_date          DATE                 null,
   bus_type             VARCHAR(30)          null,
   settle_type          INT4                 null,
   supplier_id          VARCHAR(20)          null,
   dep_code             VARCHAR(20)          null,
   ap_no                VARCHAR(30)          null,
   ap_money             DECIMAL              null,
   profit_no            VARCHAR(30)          null,
   profit_money         DECIMAL              null,
   person_code          VARCHAR(20)          null,
   pay_code             VARCHAR(10)          null,
   cexch_name           VARCHAR(10)          null,
   handler              VARCHAR(20)          null,
   is_handle            BOOL                 null,
   audit_time           TIMESTAMP            null,
   status               INT2                 null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   closer               VARCHAR(20)          null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   memo                 VARCHAR(200)         null,
   constraint PK_PU_SETTLE_VOUCH primary key (id),
   constraint AK_KEY_2_PU_SETTL unique (no)
);

/*==============================================================*/
/* Table: pu_settle_vouchs                                      */
/*==============================================================*/
create table pu_settle_vouchs (
   ID                   SERIAL not null,
   settle_no            VARCHAR(30)          not null,
   rd_no                VARCHAR(30)          not null,
   rds_note             VARCHAR(250)         null,
   bus_no               VARCHAR(30)          null,
   product_code         VARCHAR(20)          not null,
   product_style        VARCHAR(20)          null,
   unit                 VARCHAR(20)          null,
   quantity             DECIMAL              null,
   price                DECIMAL              null,
   s_price              DECIMAL              null,
   tax_price            DECIMAL              null,
   amount               DECIMAL              null,
   memo                 VARCHAR(220)         null,
   constraint PK_PU_SETTLE_VOUCHS primary key (ID)
);

/*==============================================================*/
/* Table: rd_in_imei                                            */
/*==============================================================*/
create table rd_in_imei (
   id                   SERIAL not null,
   imei                 VARCHAR(30)          not null,
   msn                  VARCHAR(30)          null,
   no                   VARCHAR(30)          not null,
   src_no               VARCHAR(30)          null,
   vouchs_id            NUMERIC(32)          not null,
   vouch_type           VARCHAR(30)          null,
   wh_code              VARCHAR(30)          not null,
   bus_code             VARCHAR(30)          null,
   product_code         VARCHAR(30)          not null,
   bus_date             DATE                 not null,
   created              TIMESTAMP            not null,
   creater              VARCHAR(30)          null,
   memo                 VARCHAR(250)         null,
   constraint PK_RD_IN_IMEI primary key (id)
);

/*==============================================================*/
/* Table: rd_out_imei                                           */
/*==============================================================*/
create table rd_out_imei (
   id                   SERIAL not null,
   imei                 VARCHAR(30)          not null,
   msn                  VARCHAR(30)          null,
   no                   VARCHAR(30)          not null,
   src_no               VARCHAR(30)          null,
   vouchs_id            NUMERIC(32)          not null,
   vouch_type           VARCHAR(30)          null,
   wh_code              VARCHAR(30)          not null,
   bus_code             VARCHAR(30)          null,
   product_code         VARCHAR(30)          not null,
   bus_date             DATE                 not null,
   creater              VARCHAR(30)          null,
   created              TIMESTAMP            not null,
   memo                 VARCHAR(250)         null,
   constraint PK_RD_OUT_IMEI primary key (id)
);

/*==============================================================*/
/* Table: rd_record                                             */
/*==============================================================*/
create table rd_record (
   id                   SERIAL not null,
   bus_date             DATE                 null,
   rd_no                VARCHAR(30)          not null,
   rd_flag              INT2                 null,
   vouch_type           VARCHAR(10)          null,
   bus_type             VARCHAR(10)          null,
   vouch_source         VARCHAR(50)          null,
   bus_no               VARCHAR(30)          null,
   wh_code              VARCHAR(10)          null,
   position_code        VARCHAR(10)          null,
   dep_code             VARCHAR(20)          null,
   person_code          VARCHAR(20)          null,
   pt_code              VARCHAR(2)           null,
   st_code              VARCHAR(2)           null,
   cus_code             VARCHAR(20)          null,
   supplier_id          VARCHAR(20)          null,
   order_no             VARCHAR(30)          null,
   bill_no              VARCHAR(30)          null,
   is_bill              BOOL                 null default false,
   handler              VARCHAR(30)          null,
   is_handle            BOOL                 null,
   audit_time           TIMESTAMP            null,
   created_by           INT8                 null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   accounter            VARCHAR(30)          null,
   keep_time            TIMESTAMP            null,
   status               INT2                 null,
   imei_audit           BOOL                 not null default false,
   memo                 VARCHAR(200)         null,
   constraint PK_RD_RECORD primary key (id, rd_no),
   constraint AK_KEY_2_RD_RECOR unique (rd_no)
);

/*==============================================================*/
/* Table: rd_records                                            */
/*==============================================================*/
create table rd_records (
   id                   SERIAL not null,
   rd_no                VARCHAR(30)          not null,
   batch                VARCHAR(25)          null,
   bus_no               VARCHAR(30)          null,
   order_no             VARCHAR(30)          null,
   src_no               VARCHAR(30)          null,
   product_code         VARCHAR(20)          null,
   product_style        VARCHAR(20)          null,
   position_code        VARCHAR(10)          null,
   unit                 VARCHAR(10)          null,
   quantity             DECIMAL              null,
   squantity            DECIMAL              null,
   unit_price           DECIMAL              null,
   money                DECIMAL              null,
   a_money              DECIMAL              null,
   memo                 VARCHAR(100)         null,
   is_account           BOOL                 not null default false,
   constraint PK_RD_RECORDS primary key (id)
);

/*==============================================================*/
/* Table: rd_trans_imei                                         */
/*==============================================================*/
create table rd_trans_imei (
   id                   SERIAL not null,
   imei                 VARCHAR(30)          not null,
   msn                  VARCHAR(30)          null,
   no                   VARCHAR(30)          not null,
   src_no               VARCHAR(30)          null,
   vouchs_id            NUMERIC(32)          not null,
   vouch_type           VARCHAR(30)          null,
   out_wh_code          VARCHAR(30)          not null,
   in_wh_code           VARCHAR(30)          not null,
   bus_code             VARCHAR(30)          null,
   product_code         VARCHAR(30)          not null,
   bus_date             DATE                 not null,
   created              TIMESTAMP            not null,
   creater              VARCHAR(30)          null,
   memo                 VARCHAR(250)         null,
   constraint PK_RD_TRANS_IMEI primary key (id)
);

/*==============================================================*/
/* Table: report_format                                         */
/*==============================================================*/
create table report_format (
   ID                   SERIAL not null,
   win_id               NUMERIC              not null,
   report_title         VARCHAR(250)         null,
   report_format        TEXT                 not null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   constraint PK_REPORT_FORMAT primary key (ID)
);

/*==============================================================*/
/* Table: reserve                                               */
/*==============================================================*/
create table reserve (
   reserve_id           SERIAL not null,
   dinner_id            VARCHAR(250)         not null,
   area_id              VARCHAR(20)          null,
   all_use              BOOL                 null,
   reserve_caption      VARCHAR(250)         null,
   reserve_date         DATE                 not null,
   type                 VARCHAR(20)          null,
   market_type_id       INT2                 null,
   reserve_by           VARCHAR(30)          null,
   phone                VARCHAR(30)          null,
   is_deposit           BOOL                 null,
   is_carte             BOOL                 null,
   other                VARCHAR(250)         null,
   status               INT2                 null,
   created_by           NUMERIC              null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updated              TIMESTAMP            null,
   memo                 VARCHAR(250)         null,
   constraint PK_RESERVE primary key (reserve_id, dinner_id)
);

/*==============================================================*/
/* Table: reserves                                              */
/*==============================================================*/
create table reserves (
   id                   SERIAL not null,
   reserve_id           NUMERIC              not null,
   dishes_id            NUMERIC              null,
   dishes_code          VARCHAR(20)          not null,
   dishes_name          VARCHAR(50)          null,
   price                DECIMAL              null,
   style                VARCHAR(50)          null,
   quantity             INT8                 null,
   constraint PK_RESERVES primary key (id, reserve_id)
);

/*==============================================================*/
/* Table: sa_dispatch_vouch                                     */
/*==============================================================*/
create table sa_dispatch_vouch (
   id                   SERIAL not null,
   no                   VARCHAR(30)          not null,
   bus_date             DATE                 null,
   bus_type             VARCHAR(10)          null,
   sa_type              VARCHAR(10)          null,
   cus_code             VARCHAR(20)          null,
   ship_address         VARCHAR(200)         null,
   linkman              VARCHAR(50)          null,
   phone                VARCHAR(50)          null,
   wh_code              VARCHAR(10)          null,
   dep_code             VARCHAR(20)          null,
   person_code          VARCHAR(20)          null,
   handler              VARCHAR(20)          null,
   audit_time           TIMESTAMP            null,
   is_handle            BOOL                 null,
   is_complete          BOOL                 null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   closer               VARCHAR(20)          null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   status               INT2                 null,
   memo                 VARCHAR(200)         null,
   constraint PK_SA_DISPATCH_VOUCH primary key (id),
   constraint AK_KEY_2_SA_DISPA unique (no)
);

/*==============================================================*/
/* Table: sa_dispatch_vouchs                                    */
/*==============================================================*/
create table sa_dispatch_vouchs (
   ID                   SERIAL not null,
   dispatch_no          VARCHAR(30)          not null,
   order_no             VARCHAR(30)          null,
   src_no               VARCHAR(30)          null,
   cus_code             VARCHAR(20)          null,
   product_code         VARCHAR(20)          not null,
   product_style        VARCHAR(20)          null,
   unit                 VARCHAR(20)          null,
   quantity             DECIMAL              null,
   price                DECIMAL              null,
   tax_price            DECIMAL              null,
   money                DECIMAL              null,
   constraint PK_SA_DISPATCH_VOUCHS primary key (ID)
);

/*==============================================================*/
/* Table: sa_order_vouch                                        */
/*==============================================================*/
create table sa_order_vouch (
   id                   SERIAL not null,
   no                   VARCHAR(30)          not null,
   bus_date             DATE                 null,
   bus_type             VARCHAR(10)          null,
   cus_code             VARCHAR(20)          null,
   wh_code              VARCHAR(10)          null,
   dep_code             VARCHAR(20)          null,
   demand_date          DATE                 null,
   project_date         DATE                 null,
   person_code          VARCHAR(20)          null,
   handler              VARCHAR(20)          null,
   audit_time           TIMESTAMP            null,
   is_handle            BOOL                 null,
   is_complete          BOOL                 null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   closer               VARCHAR(20)          null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   status               INT2                 null,
   memo                 VARCHAR(200)         null,
   constraint PK_SA_ORDER_VOUCH primary key (id),
   constraint AK_KEY_2_SA_ORDER unique (no)
);

/*==============================================================*/
/* Table: sa_order_vouchs                                       */
/*==============================================================*/
create table sa_order_vouchs (
   ID                   SERIAL not null,
   order_no             VARCHAR(30)          not null,
   cus_code             VARCHAR(20)          null,
   product_code         VARCHAR(20)          not null,
   product_style        VARCHAR(20)          null,
   unit                 VARCHAR(20)          null,
   quantity             DECIMAL              null,
   out_quantity         DECIMAL              null default 0,
   re_quantity          DECIMAL              null default 0,
   is_complete          BOOL                 null,
   price                DECIMAL              null,
   tax_price            DECIMAL              null,
   money                DECIMAL              null,
   toq                  INT8                 null,
   constraint PK_SA_ORDER_VOUCHS primary key (ID)
);

/*==============================================================*/
/* Table: sa_price_report                                       */
/*==============================================================*/
create table sa_price_report (
   id                   SERIAL not null,
   no                   VARCHAR(30)          not null,
   product_code         VARCHAR(30)          not null,
   price                DECIMAL              not null,
   uprice1              DECIMAL              null,
   uprice2              DECIMAL              null,
   uprice3              DECIMAL              null,
   sales_cost           DECIMAL              null,
   low_sum              DECIMAL              null,
   description          VARCHAR(250)         null,
   updated_by           NUMERIC              null,
   updated              TIMESTAMP            null,
   constraint PK_SA_PRICE_REPORT primary key (id)
);

/*==============================================================*/
/* Table: sa_price_report_his                                   */
/*==============================================================*/
create table sa_price_report_his (
   id                   SERIAL not null,
   no                   VARCHAR(30)          not null,
   product_code         VARCHAR(30)          not null,
   price                DECIMAL              not null,
   uprice1              DECIMAL              null,
   uprice2              DECIMAL              null,
   uprice3              DECIMAL              null,
   sales_cost           DECIMAL              null,
   low_sum              DECIMAL              null,
   description          VARCHAR(250)         null,
   updated_by           NUMERIC              null,
   updated              TIMESTAMP            null,
   constraint PK_SA_PRICE_REPORT_HIS primary key (id)
);

/*==============================================================*/
/* Table: sa_promotions                                         */
/*==============================================================*/
create table sa_promotions (
   promotions_id        SERIAL not null,
   promotions_name      VARCHAR(200)         null,
   promotions_title     VARCHAR(200)         null,
   promotions_type      INT2                 null,
   price                DECIMAL              null,
   promotions_price     DECIMAL              null,
   coupon               TEXT                 null,
   purchase_notes       TEXT                 null,
   promotions_date      TIMESTAMP            null,
   status               INT2                 null,
   created_by           NUMERIC              null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updated              TIMESTAMP            null,
   constraint PK_SA_PROMOTIONS primary key (promotions_id)
);

/*==============================================================*/
/* Table: sa_promotions_child                                   */
/*==============================================================*/
create table sa_promotions_child (
   id                   SERIAL not null,
   promotions_id        NUMERIC              null,
   dishes_id            NUMERIC              null,
   dishes_code          VARCHAR(20)          not null,
   dishes_name          VARCHAR(50)          null,
   price                DECIMAL              null,
   style                VARCHAR(50)          null,
   quantity             INT8                 null,
   constraint PK_SA_PROMOTIONS_CHILD primary key (id)
);

/*==============================================================*/
/* Table: sa_queue                                              */
/*==============================================================*/
create table sa_queue (
   queue_id             SERIAL not null,
   queue_date           DATE                 null,
   market_type_id       INT2                 null,
   status               INT2                 null,
   dinner_id            VARCHAR(10)          null,
   in_date              TIMESTAMP            null,
   member_code          VARCHAR(20)          null,
   queue_no             VARCHAR(10)          null,
   count                INT4                 null,
   created_by           NUMERIC              null,
   created              TIMESTAMP            null,
   creater              VARCHAR(20)          null,
   memo                 VARCHAR(200)         null,
   constraint PK_SA_QUEUE primary key (queue_id)
);

/*==============================================================*/
/* Table: sa_queue_child                                        */
/*==============================================================*/
create table sa_queue_child (
   id                   SERIAL not null,
   queue_id             NUMERIC              not null,
   dishes_id            NUMERIC              null,
   dishes_code          VARCHAR(20)          not null,
   dishes_name          VARCHAR(50)          null,
   price                DECIMAL              null,
   style                VARCHAR(50)          null,
   unit                 CHAR(10)             null,
   quantity             DECIMAL              null,
   constraint PK_SA_QUEUE_CHILD primary key (id, queue_id)
);

/*==============================================================*/
/* Table: sa_queue_his                                          */
/*==============================================================*/
create table sa_queue_his (
   queue_id             NUMERIC              not null,
   queue_date           TIMESTAMP            null,
   market_type_id       INT2                 null,
   status               INT2                 null,
   dinner_id            VARCHAR(10)          null,
   count                INT4                 null,
   in_date              TIMESTAMP            null,
   member_code          VARCHAR(20)          null,
   queue_no             VARCHAR(10)          null,
   created_by           VARCHAR(30)          null,
   created              TIMESTAMP            null,
   constraint PK_SA_QUEUE_HIS primary key (queue_id)
);

/*==============================================================*/
/* Table: sa_settle_record                                      */
/*==============================================================*/
create table sa_settle_record (
   id                   SERIAL not null,
   settle_id            VARCHAR(30)          not null,
   business_date        DATE                 null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   settlement_amount    DECIMAL              null,
   amount               DECIMAL              null,
   offet_val            DECIMAL              null,
   favorable_val        DECIMAL              null,
   favorable_code       VARCHAR(100)         null,
   odd_change           DECIMAL              null,
   sales_id             VARCHAR(230)         null,
   service_id           VARCHAR(20)          null,
   member_id            NUMERIC              null,
   status               INT2                 null,
   cash_type            INT2                 null,
   memo                 VARCHAR(250)         null,
   market_type_id       INT2                 null,
   constraint PK_SA_SETTLE_RECORD primary key (id),
   constraint AK_KEY_3_SA_SETTL unique (settle_id)
);

/*==============================================================*/
/* Index: Index_settle_id                                       */
/*==============================================================*/
create  index Index_settle_id on sa_settle_record (
settle_id
);

/*==============================================================*/
/* Table: sa_settle_records                                     */
/*==============================================================*/
create table sa_settle_records (
   id                   SERIAL not null,
   settle_id            VARCHAR(30)          not null,
   dishes_id            NUMERIC              not null,
   dishes_code          VARCHAR(20)          not null,
   quantity             DECIMAL              not null,
   style                VARCHAR(50)          null,
   unit                 VARCHAR(20)          null,
   price                DECIMAL              null,
   settle_price         DECIMAL              null,
   discount             DECIMAL              null,
   sales_id             VARCHAR(30)          null,
   constraint PK_SA_SETTLE_RECORDS primary key (id)
);

/*==============================================================*/
/* Table: sa_settle_vouch                                       */
/*==============================================================*/
create table sa_settle_vouch (
   id                   SERIAL not null,
   no                   VARCHAR(30)          not null,
   pt_code              VARCHAR(10)          null,
   order_no             VARCHAR(30)          null,
   rd_no                VARCHAR(30)          null,
   bus_type             VARCHAR(30)          null,
   settle_date          DATE                 null,
   settle_type          INT4                 null,
   cus_code             VARCHAR(20)          null,
   dep_code             VARCHAR(20)          null,
   ap_no                VARCHAR(30)          null,
   ap_money             DECIMAL              null,
   profit_no            VARCHAR(30)          null,
   profit_money         DECIMAL              null,
   person_code          VARCHAR(20)          null,
   pay_code             VARCHAR(10)          null,
   cexch_name           VARCHAR(10)          null,
   handler              VARCHAR(20)          null,
   is_handle            BOOL                 null,
   audit_time           TIMESTAMP            null,
   status               INT2                 null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   closer               VARCHAR(20)          null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   memo                 VARCHAR(200)         null,
   constraint PK_SA_SETTLE_VOUCH primary key (id),
   constraint AK_KEY_2_SA_SETTL unique (no)
);

/*==============================================================*/
/* Table: sa_settle_vouchs                                      */
/*==============================================================*/
create table sa_settle_vouchs (
   ID                   SERIAL not null,
   settle_no            VARCHAR(30)          not null,
   rd_no                VARCHAR(30)          not null,
   rds_note             VARCHAR(250)         null,
   bus_no               VARCHAR(30)          null,
   product_code         VARCHAR(20)          not null,
   product_style        VARCHAR(20)          null,
   unit                 VARCHAR(20)          null,
   quantity             DECIMAL              null,
   price                DECIMAL              null,
   s_price              DECIMAL              null,
   tax_price            DECIMAL              null,
   amount               DECIMAL              null,
   memo                 VARCHAR(220)         null,
   constraint PK_SA_SETTLE_VOUCHS primary key (ID)
);

/*==============================================================*/
/* Table: sales_record                                          */
/*==============================================================*/
create table sales_record (
   id                   SERIAL not null,
   sales_id             VARCHAR(30)          not null,
   dinner_id            VARCHAR(200)         not null,
   business_date        DATE                 null,
   bus_type             VARCHAR(10)          null,
   consume_num          INT4                 null,
   tastes_type          INT4                 null,
   tastes               VARCHAR(100)         null,
   saler_id             VARCHAR(20)          null,
   service_id           VARCHAR(20)          null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   settlement_time      TIMESTAMP            null,
   is_settlement        BOOL                 null,
   settlement_id        VARCHAR(250)         null,
   member_id            NUMERIC              null,
   settlement_amount    DECIMAL              null,
   used_amount          DECIMAL              null,
   market_type_id       INT2                 null,
   is_join              BOOL                 null,
   status               INT2                 null,
   memo                 VARCHAR(250)         null,
   constraint PK_SALES_RECORD primary key (id),
   constraint AK_KEY_2_SALES_RE unique (sales_id)
);

/*==============================================================*/
/* Index: Index_sales_id                                        */
/*==============================================================*/
create  index Index_sales_id on sales_record (
sales_id
);

/*==============================================================*/
/* Table: sales_records                                         */
/*==============================================================*/
create table sales_records (
   id                   SERIAL not null,
   sales_id             VARCHAR(30)          not null,
   dishes_id            NUMERIC              not null,
   dishes_code          VARCHAR(20)          not null,
   unit                 VARCHAR(20)          null,
   dishes_by            INT4                 null,
   cook                 VARCHAR(20)          null,
   quantity             DECIMAL              not null default 0,
   back_quantity        DECIMAL              null,
   style                VARCHAR(50)          null,
   price                DECIMAL              null,
   serve_status         INT2                 null,
   serve_time           TIMESTAMP            null,
   urge_time            TIMESTAMP            null,
   status               INT2                 null default 0,
   taste_id             INT2                 null default 0,
   constraint PK_SALES_RECORDS primary key (id)
);

/*==============================================================*/
/* Table: st_check_vouch                                        */
/*==============================================================*/
create table st_check_vouch (
   id                   SERIAL not null,
   no                   VARCHAR(30)          not null,
   bus_date             DATE                 null,
   bus_type             VARCHAR(10)          null,
   sa_type              VARCHAR(10)          null,
   cus_code             VARCHAR(20)          null,
   wh_code              VARCHAR(10)          null,
   dep_code             VARCHAR(20)          null,
   person_code          VARCHAR(20)          null,
   handler              VARCHAR(20)          null,
   audit_time           TIMESTAMP            null,
   is_handle            BOOL                 null,
   is_complete          BOOL                 null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   closer               VARCHAR(20)          null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   status               INT2                 null,
   memo                 VARCHAR(200)         null,
   constraint PK_ST_CHECK_VOUCH primary key (id),
   constraint AK_KEY_2_ST_CHECK unique (no)
);

/*==============================================================*/
/* Table: st_check_vouchs                                       */
/*==============================================================*/
create table st_check_vouchs (
   ID                   SERIAL not null,
   check_no             VARCHAR(30)          not null,
   cus_code             VARCHAR(30)          null,
   wh_code              VARCHAR(30)          null,
   product_code         VARCHAR(20)          not null,
   product_style        VARCHAR(20)          null,
   unit                 VARCHAR(20)          null,
   quantity             DECIMAL              null,
   price                DECIMAL              null,
   tax_price            DECIMAL              null,
   money                DECIMAL              null,
   constraint PK_ST_CHECK_VOUCHS primary key (ID)
);

/*==============================================================*/
/* Table: st_trans_vouch                                        */
/*==============================================================*/
create table st_trans_vouch (
   id                   SERIAL not null,
   tv_no                VARCHAR(30)          not null,
   tv_date              DATE                 not null,
   owh_code             VARCHAR(20)          not null,
   iwh_code             VARCHAR(20)          not null,
   dep_code             VARCHAR(20)          null,
   person_code          VARCHAR(20)          null,
   ord_no               VARCHAR(30)          null,
   ird_no               VARCHAR(30)          null,
   handler              VARCHAR(20)          null,
   audit_time           TIMESTAMP            null,
   is_handle            BOOL                 null,
   status               INT2                 null,
   created_by           NUMERIC              null,
   creater              VARCHAR(20)          null,
   created              TIMESTAMP            null,
   updated_by           NUMERIC              null,
   updater              VARCHAR(20)          null,
   updated              TIMESTAMP            null,
   memo                 VARCHAR(200)         null,
   imei_audit           BOOL                 not null default false,
   constraint PK_ST_TRANS_VOUCH primary key (id),
   constraint AK_KEY_2_ST_TRANS unique (tv_no)
);

/*==============================================================*/
/* Table: st_trans_vouchs                                       */
/*==============================================================*/
create table st_trans_vouchs (
   ID                   SERIAL not null,
   tv_no                VARCHAR(30)          not null,
   product_code         VARCHAR(20)          null,
   product_style        VARCHAR(20)          null,
   unit                 VARCHAR(10)          null,
   quantity             DECIMAL              null,
   unit_price           DECIMAL              null,
   money                DECIMAL              null,
   constraint PK_ST_TRANS_VOUCHS primary key (ID)
);

/*==============================================================*/
/* Table: stock                                                 */
/*==============================================================*/
create table stock (
   ID                   SERIAL not null,
   product_code         VARCHAR(20)          not null,
   wh_code              VARCHAR(10)          not null,
   style                VARCHAR(20)          null,
   position_code        VARCHAR(10)          null,
   unit                 VARCHAR(20)          null,
   sum                  DECIMAL              null,
   ready_sum            DECIMAL              null,
   can_sum              DECIMAL              null,
   status               DECIMAL              null,
   memo                 VARCHAR(200)         null,
   constraint PK_STOCK primary key (ID)
);

/*==============================================================*/
/* Table: stock_cus_imei                                        */
/*==============================================================*/
create table stock_cus_imei (
   id                   SERIAL not null,
   imei                 VARCHAR(30)          not null,
   msn                  VARCHAR(30)          null,
   no                   VARCHAR(30)          not null,
   vouchs_id            NUMERIC(32)          not null,
   wh_code              VARCHAR(30)          not null,
   bus_code             VARCHAR(30)          null,
   product_code         VARCHAR(30)          not null,
   bus_date             DATE                 not null,
   created              TIMESTAMP            not null,
   creater              VARCHAR(30)          null,
   is_settle            BOOL                 null,
   settle_no            VARCHAR(30)          null,
   settle_date          DATE                 null,
   memo                 VARCHAR(250)         null,
   constraint PK_STOCK_CUS_IMEI primary key (id),
   constraint AK_KEY_2_STOCK_CU unique (imei)
);

/*==============================================================*/
/* Table: stock_imei                                            */
/*==============================================================*/
create table stock_imei (
   id                   SERIAL not null,
   imei                 VARCHAR(30)          not null,
   msn                  VARCHAR(30)          null,
   no                   VARCHAR(30)          not null,
   vouchs_id            NUMERIC(32)          not null,
   wh_code              VARCHAR(30)          not null,
   product_code         VARCHAR(30)          not null,
   bus_date             DATE                 not null,
   created              TIMESTAMP            not null,
   memo                 VARCHAR(250)         null,
   creater              VARCHAR(30)          null,
   constraint PK_STOCK_IMEI primary key (id),
   constraint AK_KEY_2_STOCK_IM unique (imei)
);

/*==============================================================*/
/* Table: system_set                                            */
/*==============================================================*/
create table system_set (
   id                   VARCHAR(3)           not null,
   name                 VARCHAR(20)          null,
   value                VARCHAR(30)          null,
   caption              VARCHAR(30)          null,
   sub_id               INT8                 null,
   yes_no               BOOL                 null,
   memo                 VARCHAR(200)         null
);

/*==============================================================*/
/* Table: tableid                                               */
/*==============================================================*/
create table tableid (
   table_code           VARCHAR(10)          not null,
   table_name           VARCHAR(20)          null,
   table_no             INT4                 null,
   table_length         INT4                 null,
   table_date           DATE                 null,
   memo                 VARCHAR(200)         null,
   constraint PK_TABLEID primary key (table_code)
);

INSERT INTO "public"."ba_ap_type" VALUES ('001', '付款单', '2');
INSERT INTO "public"."ba_ap_type" VALUES ('002', '收款单', '1');
INSERT INTO "public"."ba_ap_type" VALUES ('003', '其他付款', '2');
INSERT INTO "public"."ba_ap_type" VALUES ('004', '其他收款', '1');

INSERT INTO "public"."ba_kcode" VALUES ('001', '现金', '1', null, 'f', '0', '', 'f', 'f', 'f', 'f');
INSERT INTO "public"."ba_kcode" VALUES ('002', '银行存款', '1', '002', 'f', '1', '', 'f', 'f', 'f', 'f');
INSERT INTO "public"."ba_kcode" VALUES ('002001', '光大银行卡', '2', '002001', 't', '1', '', 't', 't', 'f', 'f');
INSERT INTO "public"."ba_kcode" VALUES ('003', '应收帐款', '1', '00', 't', '1', '', 't', 't', 'f', 'f');

INSERT INTO "public"."ba_unit" VALUES ('1', '台', '',1);
INSERT INTO "public"."ba_unit" VALUES ('2', '件', '',1);

-- ----------------------------
-- Records of ba_market_type
-- ----------------------------
INSERT INTO "public"."ba_market_type" VALUES ('1', '早市', '07:30:00', '早茶，早餐', '必须要说啊，这个');
INSERT INTO "public"."ba_market_type" VALUES ('2', '午市', '11:00:00', '午餐', '不错');
INSERT INTO "public"."ba_market_type" VALUES ('4', '晚市', '17:00:00', '晚餐', '生意最好达');

-- ----------------------------
-- Records of posset
-- ----------------------------
INSERT INTO "public"."ba_posset" VALUES ('001', 'Pos Set Interval', '30', '界面刷新间隔', null, null);
INSERT INTO "public"."ba_posset" VALUES ('002', 'A warning', '00:06:00', '一级警告', null, null);
INSERT INTO "public"."ba_posset" VALUES ('003', 'B warning', '00:12:00', '二级警告', null, null);
INSERT INTO "public"."ba_posset" VALUES ('004', 'is wait clear or end', '0', '结算完,点菜单是变为待清状态,还是结束,默认是待清', null, null);
INSERT INTO "public"."ba_posset" VALUES ('005', 'auto print', '0', '超过二级警告自动打印催菜单', null, null);
INSERT INTO "public"."ba_posset" VALUES ('006', 'select chef', '0', '变更状态是否选择厨师', null, null);
INSERT INTO "public"."ba_posset" VALUES ('007', 'print head', null, '打印票据头', null, null);
INSERT INTO "public"."ba_posset" VALUES ('008', 'print footer', null, '打印票据页尾', null, null);

-- ----------------------------
-- Records of system_set
-- ----------------------------
INSERT INTO "public"."system_set" VALUES ('001', '采购业务必有订单', '', '采购业务必有订单', '5', 't', null);
INSERT INTO "public"."system_set" VALUES ('002', '到货审核生成入库', '', '到货审核生成入库', '5', 't', null);
INSERT INTO "public"."system_set" VALUES ('601', '销售业务必有订单', '', '销售业务必有订单', '6', 'f', null);
INSERT INTO "public"."system_set" VALUES ('602', '发货审核生成入库', '', '发货审核生成入库', '6', 't', null);
INSERT INTO "public"."system_set" VALUES ('603', '允许超商品可用量发货', '', '允许超商品可用量发货', '6', 'f', null);

-- ----------------------------
-- Records of taste
-- ----------------------------
INSERT INTO "public"."ba_taste" VALUES ('1', '少盐', '不错');
INSERT INTO "public"."ba_taste" VALUES ('2', '少味精', '真的');

-- ----------------------------
-- Records of ba_vouch_type
-- ----------------------------
INSERT INTO "public"."ba_vouch_type" VALUES ('01', '采购入库单', '外购入库单');
INSERT INTO "public"."ba_vouch_type" VALUES ('02', '销售出库单', '销售出库单');
INSERT INTO "public"."ba_vouch_type" VALUES ('03', '产品入库单', '产品入库单');
INSERT INTO "public"."ba_vouch_type" VALUES ('04', '产品出库单', '产品出库单');
INSERT INTO "public"."ba_vouch_type" VALUES ('05', '其他入库单', '调拨入库 其他入库 盘盈入库');
INSERT INTO "public"."ba_vouch_type" VALUES ('06', '材料出库单', '生产领料单');
INSERT INTO "public"."ba_vouch_type" VALUES ('07', '其他出库单', '调拨出库 其他出库 盘亏出库');
INSERT INTO "public"."ba_vouch_type" VALUES ('08', '仓库调拨单', '仓库调拨单');
INSERT INTO "public"."ba_vouch_type" VALUES ('09', '委托加工入库单', '委托加工入库单');
INSERT INTO "public"."ba_vouch_type" VALUES ('10', '仓库盘点单', '盘盈入库单 盘亏毁损单');
INSERT INTO "public"."ba_vouch_type" VALUES ('11', '委托代销出库单', '委托代销出库单');
INSERT INTO "public"."ba_vouch_type" VALUES ('12', '委托代销红字出库单', '委托代销退货单');
INSERT INTO "public"."ba_vouch_type" VALUES ('14', '红字外购入库单', '采购退货');
INSERT INTO "public"."ba_vouch_type" VALUES ('15', '红字销售出库单', '销售退货');
INSERT INTO "public"."ba_vouch_type" VALUES ('16', '采购订单', '采购订单');
INSERT INTO "public"."ba_vouch_type" VALUES ('17', '采购到货单', '采购到货/通知单');
INSERT INTO "public"."ba_vouch_type" VALUES ('18', '销售订单', '销售订单');
INSERT INTO "public"."ba_vouch_type" VALUES ('19', '销售发货单', '销售发货单');

CREATE OR REPLACE VIEW st_stock_query AS 
 SELECT l1.id, l1.wh_code, l1.type_id, l1.product_code, l1.product_name, 
    l1.unit, l1.sum, l1.r_sum, COALESCE(l2.c_sum, 0::numeric) AS c_sum
   FROM ( SELECT f.id, f.wh_code, f.type_id, f.product_code, f.product_name, 
            f.unit, f.sum, COALESCE(h.r_sum, 0::numeric) AS r_sum
           FROM ( SELECT a.id, a.product_code, a.wh_code, a.style, 
                    a.position_code, a.unit, a.sum, a.ready_sum, a.can_sum, 
                    a.status, a.memo, b.product_name, b.type_id
                   FROM stock a, ba_product b
                  WHERE a.product_code::text = b.product_code::text) f
      LEFT JOIN ( SELECT d.wh_code, c.product_code, sum(c.quantity) AS r_sum
                   FROM rd_records c, rd_record d
                  WHERE c.rd_no::text = d.rd_no::text AND d.is_handle = false AND d.rd_flag = 1
                  GROUP BY d.wh_code, c.product_code) h ON f.product_code::text = h.product_code::text AND f.wh_code::text = h.wh_code::text) l1
   LEFT JOIN ( SELECT d2.wh_code, c2.product_code, sum(c2.quantity) AS c_sum
           FROM rd_records c2, rd_record d2
          WHERE c2.rd_no::text = d2.rd_no::text AND d2.is_handle = false AND d2.rd_flag = 2
          GROUP BY d2.wh_code, c2.product_code) l2 ON l1.product_code::text = l2.product_code::text AND l1.wh_code::text = l2.wh_code::text
  ORDER BY l1.id;

