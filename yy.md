# 编码规则

> **系统配置 -> 编码管理**   



## 编码规则定义

1. **编码规则定义节点列表**

   **uri**：/iuap-saas-billcode-service/billcodeobj/queryBillObj

   **mvc**：PubBcrObjController.queryBillObj()、PubBcrObj、PAP_BCR_OBJ

   ```sql
   SELECT * FROM PAP_BCR_OBJ;
   ```

2. **节点的编码规则列表**

   **uri**：/iuap-saas-billcode-service/billcode/queryCodeRuleByBillObj

   **params**：querydata: {"pageIndex":1,"applyid":"TERMINAL_STORE","pageSize":12}

   **mvc**：BillCodeController.queryCodeRuleByBillObj()、PubBcrRulebase、PAP_BCR_RULEBASE、PAP_BCR_OBJ

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

   **uri**：/iuap-saas-billcode-service/pub_bcr_cp/getByPkBillObj?pkBillObj=TERMINAL_STORE

   **mvc**：PubBcrCandidatePropController.getByPkBillObj()、PubBcrCandidateProp、PAP_BCR_CANDIDATEPROP

   ```sql
   select * from PAP_BCR_CANDIDATEPROP where pk_bcr_obj = 'TERMINAL_STORE';
   ```

   **uri**：/iuap-saas-billcode-service/billcode/queryCodeRuleByPk/064abfdbb8dd4b00a189d9ad5083c58c

   **mvc**：BillCodeController.queryCodeRuleByPk()、PubBcrElem、PAP_BCR_ELEM

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

   

