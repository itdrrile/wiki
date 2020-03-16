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

   



