# 编码规则

> **系统配置 -> 编码管理**   



## 编码规则定义

1. **编码规则定义节点列表**

   - **uri**：/iuap-saas-billcode-service/billcodeobj/queryBillObj

   - **mvc**：PubBcrObjController.queryBillObj()、PubBcrObj、PAP_BCR_OBJ

   ```sql
   SELECT * FROM PAP_BCR_OBJ;
   ```

2. **节点的编码规则列表**

   - **uri**：/iuap-saas-billcode-service/billcode/queryCodeRuleByBillObj

   - **params**：querydata: {"pageIndex":1,"applyid":"TERMINAL_STORE","pageSize":12}

   - **mvc**：BillCodeController.queryCodeRuleByBillObj()、PubBcrRulebase、PAP_BCR_RULEBASE、PAP_BCR_OBJ

   ```sql
   SELECT
   	r.pk_billcodebase,
   	r.pkbillobj,
   	r.rulecode,
   	r.rulename,
   	r.rulename2,
   	r.rulename3,
   	r.rulename4,
   	r.rulename5,
   	r.rulename6,
   	r.codemode,
   	r.iseditable,
   	r.isautofill,
   	r.format,
   	r.isdefault,
   	r.isused,
   	r.islenvar,
   	r.isgetpk,
   	r.renterid,
   	r.sysid,
   	r.createdate,
   	o. NAME applyname,
   	o.name2 applyname2,
   	o.name3 applyname3,
   	o.name4 applyname4,
   	o.name5 applyname5,
   	o.name6 applyname6
   FROM
   	pap_bcr_rulebase r
   JOIN pap_bcr_obj o ON r.pkbillobj = o.pk_billobj
   WHERE
   	r.renterid = 'tenant'
   AND r.sysid = 'wbalone'
   AND r.pkbillobj = 'TERMINAL_STORE';
   ```

3. **编码规则详情**

   - **uri**：/iuap-saas-billcode-service/pub_bcr_cp/getByPkBillObj?pkBillObj=TERMINAL_STORE

   - **mvc**：PubBcrCandidatePropController.getByPkBillObj()、PubBcrCandidateProp、PAP_BCR_CANDIDATEPROP

   ```sql
   select * from PAP_BCR_CANDIDATEPROP where pk_bcr_obj = 'TERMINAL_STORE';
   ```

   - **uri**：/iuap-saas-billcode-service/billcode/queryCodeRuleByPk/064abfdbb8dd4b00a189d9ad5083c58c

   - **mvc**：BillCodeController.queryCodeRuleByPk()、PubBcrElem、PAP_BCR_ELEM

   ```sql
   SELECT
   	pk_billcodeelem,
   	pk_billcodebase,
   	elemtype,
   	elemvalue,
   	elemlenth,
   	isrefer,
   	eorder,
   	fillstyle,
   	datedisplayformat,
   	fillsign,
   	createdate
   FROM
   	pap_bcr_elem
   WHERE
   	pk_billcodebase = '064abfdbb8dd4b00a189d9ad5083c58c'
   ORDER BY
   	eorder;
   ```

4. **编码规则：流水号管理**

   - **uri**：/iuap-saas-billcode-service/billcodeSn/querySn
   - **params**：querydata:{"pageSize":7,"pageNum":1,"pkrulebase":"491d5eb225804403a9141b3bd9a6f58c"}
   - **mvc**：BillCodeSnController.querySnBySearchMap()、PubBcrSn、PAP_BCR_SN
   
   ```sql
   SELECT
   	pk_billcodesn,
   	pk_billcodebase,
   	markstr,
   	lastsn,
   	markstrdesc
   FROM
   	PAP_BCR_SN
   WHERE
   	pk_billcodebase = '491d5eb225804403a9141b3bd9a6f58c';
   ```
   
5. **编码规则：断号查询**

   - **uri**：/iuap-saas-billcode-service/billcodeRtn/queryRtn
   - **params**：querydata: {"pageSize":7,"pageNum":1,"pkrulebase":"491d5eb225804403a9141b3bd9a6f58c"}
   - **mvc**：BillCodeRtnController.queryRtnBySearchMap()、PubBcrReturn、PAP_BCR_RETURN

   ```sql
   SELECT
   	pk_billcodertn,
   	pk_billcodebase,
   	markstr,
   	rtnsn,
   	markstrdesc
   FROM
   	pap_bcr_return
   WHERE
   	pk_billcodebase = '491d5eb225804403a9141b3bd9a6f58c';
   ```

6. **编码规则：设为默认**

   - **uri**：/iuap-saas-billcode-service/billcode/queryDefaultCodeRule
   - **params**：pkbillobj=SUPPLIER&pkBillcodebase=491d5eb225804403a9141b3bd9a6f58c&defaultflag=true
   - **mvc**：BillCodeController.queryDefaultCodeRule()、PubBcrRulebase、PAP_BCR_RULEBASE

   ```sql
   UPDATE PAP_BCR_RULEBASE
   SET isdefault = 'Y'
   WHERE
   	pk_billcodebase = '491d5eb225804403a9141b3bd9a6f58c'
   AND renterid = 'tenant'
   AND sysid = 'wbalone';
   ```



## 编码映射



## 编码对象管理

1. **编码规则列表**

   - **uri**：/iuap-saas-billcode-service/billcodeobj/queryAll
   - **mvc**：PubBcrObjController.queryAll()、PubBcrObj、PAP_BCR_OBJ

   ```sql
   SELECT * FROM PAP_BCR_OBJ;
   ```

2. **编码对象属性**

   - **uri**：/iuap-saas-billcode-service/pub_bcr_cp/getByPkBillObjsWithPage
   - **params**：pkBcrObj=OPPM_LEAD&pageIndex=0&pageSize=10
   - **mvc**：PubBcrCandidatePropController.getByPkBillObjsWithPage()、PubBcrCandidateProp、PAP_BCR_CANDIDATEPROP

   ```sql
   SELECT
   	pk,
   	pk_bcr_obj,
   	en_prop_name,
   	display_name,
   	display_name2,
   	display_name3,
   	display_name4,
   	display_name5,
   	display_name6,
   	elem_type,
   	mapping_entity,
   	create_date
   FROM
   	PAP_BCR_CANDIDATEPROP
   WHERE
   	pk_bcr_obj = 'OPPM_LEAD';
   ```



## 映射对象管理

1. **映射对象管理列表**

   - **uri**：/iuap-saas-billcode-service/pub_bcr_me/getAllAndLikeSearch
   - **params**：pageIndex=0&pageSize=10
   - **mvc**：PubBcrMappingEntityController.getAllAndLikeSearch()、PubBcrMappingEntity、PAP_BCR_MAPPINGENTITY

   ```sql
   SELECT
   	pk,
   	code,
   	name2,
   	name3,
   	name4,
   	name5,
   	name6,
   	NAME,
   	ref_code,
   	md_en_id,
   	create_date,
   	tenantid,
   	sysid
   FROM
   	PAP_BCR_MAPPINGENTITY;
   ```

   



# 常见问题汇总

> 记录经常碰到的问题



## 用户、角色、数据权限

- 【绿厨项目】 角色对应的客户数据权限出现了两种： 客户及下级客户、区域及下级区域

  > 问题原因：角色权限分配表common_role_type存在脏数据，存在ieop_role中没有的role_id
  >
  > 解决： 脚本删除脏数据
  >
  > update common_role_type set dr = 1 where ROLE_ID not in (select id from IEOP_ROLE);
  
- 添加角色数据权限需要提供的脚本（以代客下单为例）

  - /fmcg-occ-base-ext/base/role-types/detail?roleId=5acaec82b01741fca044c81df8f1eed7

    - 查询自定义档案中配置的启用的数据权限实体

    ```sql
    select * from BASE_CUST_DOC_DEF where dr = 0 and IS_ENABLE = 1 and CUST_DOC_CODE = 'xlx108';
    ```

    - 生成代客下单自定义档案中配置的数据权限实体

    ```sql
    INSERT INTO BASE_CUST_DOC_DEF ("ID", "CODE", "NAME", "DESCRIPTION", "DR", "TS", "CREATOR", "CREATION_TIME", "MODIFIER", "MODIFIED_TIME", "STATUS", "CUST_DOC_ID", "CUST_DOC_CODE", "REMARK", "EXT01", "EXT02", "EXT03", "EXT04", "EXT05", "EXT06", "EXT07", "EXT08", "EXT09", "EXT10", "IS_ENABLE") VALUES ('0Ibbx6xrfQHCr5eU9jlS', 'order', '代客下单', NULL, '0', SYSDATE, '301', SYSDATE, NULL, NULL, NULL, 'f5d6caf6-b99e-4066-8207-9b5d2d8f1ea8', 'xlx108', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '1');
    ```

  - /fmcg-occ-base-ext/base/role-types/bus_datatypes

    - 查询数据权限表（比如客户）

      ```sql
      select * from COMMON_DATARIGHT_FILED where ENTITY = 'customer' order by RIGHT_TYPE;
      ```

    - 生成代客下单数据权限

      ```sql
      INSERT INTO COMMON_DATARIGHT_FILED ("ID", "ENTITY", "RIGHT_TYPE", "RIGHT_FILED") VALUES ('order_person', 'order', '1', 'salesman');
      INSERT INTO COMMON_DATARIGHT_FILED ("ID", "ENTITY", "RIGHT_TYPE", "RIGHT_FILED") VALUES ('order_customer', 'order', '2', 'customer.id');
      INSERT INTO COMMON_DATARIGHT_FILED ("ID", "ENTITY", "RIGHT_TYPE", "RIGHT_FILED") VALUES ('order_customers', 'order', '3', 'customer.id');
      INSERT INTO COMMON_DATARIGHT_FILED ("ID", "ENTITY", "RIGHT_TYPE", "RIGHT_FILED") VALUES ('order_marketareas', 'order', '4', 'customer.customerAreas.cityMarketArea.id');
      INSERT INTO COMMON_DATARIGHT_FILED ("ID", "ENTITY", "RIGHT_TYPE", "RIGHT_FILED") VALUES ('order_departments', 'order', '5', 'saleDept.id');
      INSERT INTO COMMON_DATARIGHT_FILED ("ID", "ENTITY", "RIGHT_TYPE", "RIGHT_FILED") VALUES ('order_organization', 'order', '6', 'saleOrg.id');
      INSERT INTO COMMON_DATARIGHT_FILED ("ID", "ENTITY", "RIGHT_TYPE", "RIGHT_FILED") VALUES ('order_organizations', 'order', '7', 'saleOrg.id');
      INSERT INTO COMMON_DATARIGHT_FILED ("ID", "ENTITY", "RIGHT_TYPE", "RIGHT_FILED") VALUES ('order_marketarea', 'order', '8', 'customer.customerAreas.cityMarketArea.id');
      INSERT INTO COMMON_DATARIGHT_FILED ("ID", "ENTITY", "RIGHT_TYPE", "RIGHT_FILED") VALUES ('order_department', 'order', '9', 'saleDept.id');
      INSERT INTO COMMON_DATARIGHT_FILED ("ID", "ENTITY", "RIGHT_TYPE", "RIGHT_FILED") VALUES ('order_persons', 'order', '10', 'salesman');
      INSERT INTO COMMON_DATARIGHT_FILED ("ID", "ENTITY", "RIGHT_TYPE", "RIGHT_FILED") VALUES ('order_allpersons', 'order', '11', 'salesman');
      ```

      



## 标准查询参数

- **分组取"或"，内连接（默认）**

  search_EQ_1~personPosts.organization.id

  search_EQ_1~personMarkets.saleOrg.id

- **分组取"或"，左连接（使用L）**

  search_EQ_1~L~personPosts.organization.id

  search_EQ_1~L~personMarkets.saleOrg.id

- **分组取"或"，右连接（使用非L）**

  search_EQ_1~R~personPosts.organization.id

  search_EQ_1~R~personMarkets.saleOrg.id



## 中间件docker

- 查看docker列表
  - docker ps
  - docker ps -a
- 启动docker
  - docker start 容器id
  - docker restart 容器id
- 删除docker
  - docker rm 容器id
- 查看日志
  - docker logs -f zookeeper-occ  
- 运行docker
  -   docker run -d --name zookeeper-occ -p 2181:2181 -v  /home/work/zookeeper/data:/data zookeeper:latest  









---



