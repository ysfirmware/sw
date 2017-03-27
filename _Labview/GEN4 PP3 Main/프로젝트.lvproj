<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="15008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="NI.SortType" Type="Int">3</Property>
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="MAIN.vi" Type="VI" URL="../MAIN.vi"/>
		<Item Name="ICON2.ico" Type="Document" URL="../ICON2.ico"/>
		<Item Name="__그림파일.pptx" Type="Document" URL="../__그림파일.pptx"/>
		<Item Name="GEN4 FTS Test Report rev1.xlsx" Type="Document" URL="../Template/GEN4 FTS Test Report rev1.xlsx"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="VISA Configure Serial Port" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port"/>
				<Item Name="VISA Configure Serial Port (Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Instr).vi"/>
				<Item Name="VISA Configure Serial Port (Serial Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Serial Instr).vi"/>
				<Item Name="Check if File or Folder Exists.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Check if File or Folder Exists.vi"/>
				<Item Name="LVPointTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVPointTypeDef.ctl"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="NI_PackedLibraryUtility.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/LVLibp/NI_PackedLibraryUtility.lvlib"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="Space Constant.vi" Type="VI" URL="/&lt;vilib&gt;/dlg_ctls.llb/Space Constant.vi"/>
				<Item Name="NI_LVConfig.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/config.llb/NI_LVConfig.lvlib"/>
				<Item Name="8.6CompatibleGlobalVar.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/8.6CompatibleGlobalVar.vi"/>
				<Item Name="Dflt Data Dir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Dflt Data Dir.vi"/>
				<Item Name="eventvkey.ctl" Type="VI" URL="/&lt;vilib&gt;/event_ctls.llb/eventvkey.ctl"/>
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
				<Item Name="System Directory Type.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/sysdir.llb/System Directory Type.ctl"/>
				<Item Name="Get System Directory.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/sysdir.llb/Get System Directory.vi"/>
				<Item Name="compatWriteText.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatWriteText.vi"/>
				<Item Name="Write File+ (string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write File+ (string).vi"/>
				<Item Name="LVRowAndColumnTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVRowAndColumnTypeDef.ctl"/>
				<Item Name="NI_report.lvclass" Type="LVClass" URL="/&lt;vilib&gt;/Utility/NIReport.llb/NI_report.lvclass"/>
				<Item Name="NI_ReportGenerationCore.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/NIReport.llb/NI_ReportGenerationCore.lvlib"/>
				<Item Name="NI_HTML.lvclass" Type="LVClass" URL="/&lt;vilib&gt;/Utility/NIReport.llb/HTML/NI_HTML.lvclass"/>
				<Item Name="Write JPEG File.vi" Type="VI" URL="/&lt;vilib&gt;/picture/jpeg.llb/Write JPEG File.vi"/>
				<Item Name="imagedata.ctl" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/imagedata.ctl"/>
				<Item Name="Check File Permissions.vi" Type="VI" URL="/&lt;vilib&gt;/picture/jpeg.llb/Check File Permissions.vi"/>
				<Item Name="Check Path.vi" Type="VI" URL="/&lt;vilib&gt;/picture/jpeg.llb/Check Path.vi"/>
				<Item Name="Directory of Top Level VI.vi" Type="VI" URL="/&lt;vilib&gt;/picture/jpeg.llb/Directory of Top Level VI.vi"/>
				<Item Name="Check Color Table Size.vi" Type="VI" URL="/&lt;vilib&gt;/picture/jpeg.llb/Check Color Table Size.vi"/>
				<Item Name="Check Data Size.vi" Type="VI" URL="/&lt;vilib&gt;/picture/jpeg.llb/Check Data Size.vi"/>
				<Item Name="Write PNG File.vi" Type="VI" URL="/&lt;vilib&gt;/picture/png.llb/Write PNG File.vi"/>
				<Item Name="Registry RtKey.ctl" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Registry RtKey.ctl"/>
				<Item Name="Generate Temporary File Path.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Generate Temporary File Path.vi"/>
				<Item Name="Search and Replace Pattern.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Search and Replace Pattern.vi"/>
				<Item Name="Path to URL.vi" Type="VI" URL="/&lt;vilib&gt;/printing/PathToURL.llb/Path to URL.vi"/>
				<Item Name="Escape Characters for HTTP.vi" Type="VI" URL="/&lt;vilib&gt;/printing/PathToURL.llb/Escape Characters for HTTP.vi"/>
				<Item Name="Open Registry Key.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Open Registry Key.vi"/>
				<Item Name="Registry SAM.ctl" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Registry SAM.ctl"/>
				<Item Name="Registry refnum.ctl" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Registry refnum.ctl"/>
				<Item Name="Registry View.ctl" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Registry View.ctl"/>
				<Item Name="STR_ASCII-Unicode.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/STR_ASCII-Unicode.vi"/>
				<Item Name="Registry WinErr-LVErr.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Registry WinErr-LVErr.vi"/>
				<Item Name="Registry Handle Master.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Registry Handle Master.vi"/>
				<Item Name="Read Registry Value Simple.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Read Registry Value Simple.vi"/>
				<Item Name="Read Registry Value Simple STR.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Read Registry Value Simple STR.vi"/>
				<Item Name="Read Registry Value.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Read Registry Value.vi"/>
				<Item Name="Read Registry Value STR.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Read Registry Value STR.vi"/>
				<Item Name="Read Registry Value DWORD.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Read Registry Value DWORD.vi"/>
				<Item Name="Registry Simplify Data Type.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Registry Simplify Data Type.vi"/>
				<Item Name="Read Registry Value Simple U32.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Read Registry Value Simple U32.vi"/>
				<Item Name="Create ActiveX Event Queue.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/ax-events.llb/Create ActiveX Event Queue.vi"/>
				<Item Name="Wait types.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/ax-events.llb/Wait types.ctl"/>
				<Item Name="Create Error Clust.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/ax-events.llb/Create Error Clust.vi"/>
				<Item Name="Wait On ActiveX Event.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/ax-events.llb/Wait On ActiveX Event.vi"/>
				<Item Name="EventData.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/ax-events.llb/EventData.ctl"/>
				<Item Name="OccFireType.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/ax-events.llb/OccFireType.ctl"/>
				<Item Name="Destroy ActiveX Event Queue.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/ax-events.llb/Destroy ActiveX Event Queue.vi"/>
				<Item Name="Close Registry Key.vi" Type="VI" URL="/&lt;vilib&gt;/registry/registry.llb/Close Registry Key.vi"/>
				<Item Name="NI_Standard Report.lvclass" Type="LVClass" URL="/&lt;vilib&gt;/Utility/NIReport.llb/Standard Report/NI_Standard Report.lvclass"/>
				<Item Name="Read PNG File.vi" Type="VI" URL="/&lt;vilib&gt;/picture/png.llb/Read PNG File.vi"/>
				<Item Name="Create Mask By Alpha.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Create Mask By Alpha.vi"/>
				<Item Name="Bit-array To Byte-array.vi" Type="VI" URL="/&lt;vilib&gt;/picture/pictutil.llb/Bit-array To Byte-array.vi"/>
				<Item Name="Write BMP File.vi" Type="VI" URL="/&lt;vilib&gt;/picture/bmp.llb/Write BMP File.vi"/>
				<Item Name="compatOverwrite.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatOverwrite.vi"/>
				<Item Name="Write BMP Data.vi" Type="VI" URL="/&lt;vilib&gt;/picture/bmp.llb/Write BMP Data.vi"/>
				<Item Name="Write BMP Data To Buffer.vi" Type="VI" URL="/&lt;vilib&gt;/picture/bmp.llb/Write BMP Data To Buffer.vi"/>
				<Item Name="Calc Long Word Padded Width.vi" Type="VI" URL="/&lt;vilib&gt;/picture/bmp.llb/Calc Long Word Padded Width.vi"/>
				<Item Name="Flip and Pad for Picture Control.vi" Type="VI" URL="/&lt;vilib&gt;/picture/bmp.llb/Flip and Pad for Picture Control.vi"/>
				<Item Name="Color to RGB.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/colorconv.llb/Color to RGB.vi"/>
				<Item Name="Built App File Layout.vi" Type="VI" URL="/&lt;vilib&gt;/AppBuilder/Built App File Layout.vi"/>
				<Item Name="Get LV Class Default Value.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/LVClass/Get LV Class Default Value.vi"/>
				<Item Name="NI_ReportGenerationToolkit.lvlib" Type="Library" URL="/&lt;vilib&gt;/addons/_office/NI_ReportGenerationToolkit.lvlib"/>
				<Item Name="Beep.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/system.llb/Beep.vi"/>
				<Item Name="NI_Excel.lvclass" Type="LVClass" URL="/&lt;vilib&gt;/Utility/NIReport.llb/Excel/NI_Excel.lvclass"/>
				<Item Name="Get File Extension.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Get File Extension.vi"/>
				<Item Name="Read JPEG File.vi" Type="VI" URL="/&lt;vilib&gt;/picture/jpeg.llb/Read JPEG File.vi"/>
				<Item Name="Handle Open Word or Excel File.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/NIReport.llb/Toolkit/Handle Open Word or Excel File.vi"/>
			</Item>
			<Item Name="SUB-module-현재 VI 경로.vi" Type="VI" URL="../SUB-module-현재 VI 경로.vi"/>
			<Item Name="_시리얼 포트-초기화.vi" Type="VI" URL="../_시리얼 포트-초기화.vi"/>
			<Item Name="RWC_Actions.ctl" Type="VI" URL="../SUB_Load and Save Controls.llb/RWC_Actions.ctl"/>
			<Item Name="Read and Write Controls to Automatic Config File.vi" Type="VI" URL="../SUB_Load and Save Controls.llb/Read and Write Controls to Automatic Config File.vi"/>
			<Item Name="Read and Write Controls to Config File.vi" Type="VI" URL="../SUB_Load and Save Controls.llb/Read and Write Controls to Config File.vi"/>
			<Item Name="SUB_Delay ms.vi" Type="VI" URL="../SUB_Delay ms.vi"/>
			<Item Name="컨트롤-CDC data.ctl" Type="VI" URL="../컨트롤-CDC data.ctl"/>
			<Item Name="컨트롤-IMU data.ctl" Type="VI" URL="../컨트롤-IMU data.ctl"/>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
			<Item Name="컨트롤-동작상태 FTS.ctl" Type="VI" URL="../컨트롤-동작상태 FTS.ctl"/>
			<Item Name="_시리얼_Mark10-연결확인.vi" Type="VI" URL="../_시리얼_Mark10-연결확인.vi"/>
			<Item Name="_시리얼_Mark10-제어 (압력설정).vi" Type="VI" URL="../_시리얼_Mark10-제어 (압력설정).vi"/>
			<Item Name="_시리얼_Mark10-셋업.vi" Type="VI" URL="../_시리얼_Mark10-셋업.vi"/>
			<Item Name="_시리얼_Mark10-데이터 수신 (게이지).vi" Type="VI" URL="../_시리얼_Mark10-데이터 수신 (게이지).vi"/>
			<Item Name="_시리얼_Mark10-설정 (이동속도).vi" Type="VI" URL="../_시리얼_Mark10-설정 (이동속도).vi"/>
			<Item Name="_시리얼_Mark10-헤드이동.vi" Type="VI" URL="../_시리얼_Mark10-헤드이동.vi"/>
			<Item Name="_시리얼_Mark10-데이터 수신 (스탠드 상태).vi" Type="VI" URL="../_시리얼_Mark10-데이터 수신 (스탠드 상태).vi"/>
			<Item Name="컨트롤-동작시험상태 FTS.ctl" Type="VI" URL="../컨트롤-동작시험상태 FTS.ctl"/>
			<Item Name="SUB-module-여러줄 문자열을 배열로 변환.vi" Type="VI" URL="../SUB-module-여러줄 문자열을 배열로 변환.vi"/>
			<Item Name="SUB-Status string update.vi" Type="VI" URL="../SUB-Status string update.vi"/>
			<Item Name="Advapi32.dll" Type="Document" URL="Advapi32.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="kernel32.dll" Type="Document" URL="kernel32.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="message_class.ctl" Type="VI" URL="../Lib_Bled112 toolkit/type_def/message_class.ctl"/>
			<Item Name="message_type.ctl" Type="VI" URL="../Lib_Bled112 toolkit/type_def/message_type.ctl"/>
			<Item Name="connection_status_bundle.ctl" Type="VI" URL="../Lib_Bled112 toolkit/type_def/connection_status_bundle.ctl"/>
			<Item Name="address_type.ctl" Type="VI" URL="../Lib_Bled112 toolkit/type_def/address_type.ctl"/>
			<Item Name="Global 1.vi" Type="VI" URL="../Global 1.vi"/>
			<Item Name="SUB-BLE SCAN.vi" Type="VI" URL="../SUB-BLE SCAN.vi"/>
			<Item Name="BLED1112_app-connection.vi" Type="VI" URL="../BLED1112_app-connection.vi"/>
			<Item Name="ble_connect_to_device.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_connect_to_device.vi"/>
			<Item Name="ble_cmd_gap_connect_direct.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_cmd_gap_connect_direct.vi"/>
			<Item Name="ble_string2hex.vi" Type="VI" URL="../Lib_Bled112 toolkit/support_vi/ble_string2hex.vi"/>
			<Item Name="ble_write_message.vi" Type="VI" URL="../Lib_Bled112 toolkit/support_vi/ble_write_message.vi"/>
			<Item Name="ble_rsp_gap_connect_direct.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_rsp_gap_connect_direct.vi"/>
			<Item Name="ble_read_specific_message.vi" Type="VI" URL="../Lib_Bled112 toolkit/support_vi/ble_read_specific_message.vi"/>
			<Item Name="ble_read_message.vi" Type="VI" URL="../Lib_Bled112 toolkit/support_vi/ble_read_message.vi"/>
			<Item Name="ble_check_payload_error.vi" Type="VI" URL="../Lib_Bled112 toolkit/support_vi/ble_check_payload_error.vi"/>
			<Item Name="ble_evt_connection_status.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_evt_connection_status.vi"/>
			<Item Name="ble_hex2string.vi" Type="VI" URL="../Lib_Bled112 toolkit/support_vi/ble_hex2string.vi"/>
			<Item Name="ble_wait_ms.vi" Type="VI" URL="../Lib_Bled112 toolkit/support_vi/ble_wait_ms.vi"/>
			<Item Name="ble_discover_handle_table.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_discover_handle_table.vi"/>
			<Item Name="ble_discover_characteristics.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_discover_characteristics.vi"/>
			<Item Name="ble_cmd_attclient_find_information.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_cmd_attclient_find_information.vi"/>
			<Item Name="ble_rsp_attclient_find_information.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_rsp_attclient_find_information.vi"/>
			<Item Name="ble_evt_attclient_find_information_found.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_evt_attclient_find_information_found.vi"/>
			<Item Name="ble_discover_services.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_discover_services.vi"/>
			<Item Name="service_type.ctl" Type="VI" URL="../Lib_Bled112 toolkit/type_def/service_type.ctl"/>
			<Item Name="ble_cmd_attclient_read_by_group_type.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_cmd_attclient_read_by_group_type.vi"/>
			<Item Name="ble_rsp_attclient_read_by_group_type.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_rsp_attclient_read_by_group_type.vi"/>
			<Item Name="ble_evt_attclient_group_found.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_evt_attclient_group_found.vi"/>
			<Item Name="ble_read_by_service_characteristic.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_read_by_service_characteristic.vi"/>
			<Item Name="ble_search_handle_by_service_and_characteristic.vi" Type="VI" URL="../Lib_Bled112 toolkit/support_vi/ble_search_handle_by_service_and_characteristic.vi"/>
			<Item Name="ble_read_by_handle.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_read_by_handle.vi"/>
			<Item Name="ble_cmd_attclient_read_by_handle.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_cmd_attclient_read_by_handle.vi"/>
			<Item Name="ble_rsp_attclient_read_by_handle.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_rsp_attclient_read_by_handle.vi"/>
			<Item Name="ble_evt_attclient_attribute_value.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_evt_attclient_attribute_value.vi"/>
			<Item Name="ble_write_by_service_characteristic.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_write_by_service_characteristic.vi"/>
			<Item Name="ble_write_by_service_characteristic_uint16.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_write_by_service_characteristic_uint16.vi"/>
			<Item Name="ble_write_by_handle_uint8array.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_write_by_handle_uint8array.vi"/>
			<Item Name="ble_cmd_attclient_attribute_write.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_cmd_attclient_attribute_write.vi"/>
			<Item Name="ble_rsp_attclient_attribute_write.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_rsp_attclient_attribute_write.vi"/>
			<Item Name="ble_evt_attclient_procedue_completed.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_evt_attclient_procedue_completed.vi"/>
			<Item Name="ble_write_by_service_characteristic_uint8array.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_write_by_service_characteristic_uint8array.vi"/>
			<Item Name="BLED1112-Set interval to min.vi" Type="VI" URL="../BLED1112-Set interval to min.vi"/>
			<Item Name="_시리얼_buf clear.vi" Type="VI" URL="../_시리얼_buf clear.vi"/>
			<Item Name="BLED1112_app-discovery scan.vi" Type="VI" URL="../BLED1112_app-discovery scan.vi"/>
			<Item Name="ble_reset_dongle_and_cnx.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_reset_dongle_and_cnx.vi"/>
			<Item Name="ble_attach_dongle.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_attach_dongle.vi"/>
			<Item Name="ble_cmd_system_reset.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_cmd_system_reset.vi"/>
			<Item Name="ble_dongle_info.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_dongle_info.vi"/>
			<Item Name="ble_cmd_system_get_info.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_cmd_system_get_info.vi"/>
			<Item Name="ble_rsp_system_get_info.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_rsp_system_get_info.vi"/>
			<Item Name="ble_scan_parameters.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_scan_parameters.vi"/>
			<Item Name="scanning_technique.ctl" Type="VI" URL="../Lib_Bled112 toolkit/type_def/scanning_technique.ctl"/>
			<Item Name="ble_cmd_gap_set_scan_parameters.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_cmd_gap_set_scan_parameters.vi"/>
			<Item Name="ble_rsp_gap_set_scan_parameters.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_rsp_gap_set_scan_parameters.vi"/>
			<Item Name="ble_discover_ble_devices.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_discover_ble_devices.vi"/>
			<Item Name="gap_discover_mode.ctl" Type="VI" URL="../Lib_Bled112 toolkit/type_def/gap_discover_mode.ctl"/>
			<Item Name="ble_starts_discovery.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_starts_discovery.vi"/>
			<Item Name="ble_cmd_gap_discover.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_cmd_gap_discover.vi"/>
			<Item Name="ble_rsp_gap_discover.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_rsp_gap_discover.vi"/>
			<Item Name="ble_evt_gap_scan_response.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_evt_gap_scan_response.vi"/>
			<Item Name="ble_parse_scan_response.vi" Type="VI" URL="../Lib_Bled112 toolkit/support_vi/ble_parse_scan_response.vi"/>
			<Item Name="advertising_package_type.ctl" Type="VI" URL="../Lib_Bled112 toolkit/type_def/advertising_package_type.ctl"/>
			<Item Name="ble_delete_repeated_scan_responses.vi" Type="VI" URL="../Lib_Bled112 toolkit/support_vi/ble_delete_repeated_scan_responses.vi"/>
			<Item Name="ble_discover_stop.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_discover_stop.vi"/>
			<Item Name="ble_cmd_end_procedure.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_cmd_end_procedure.vi"/>
			<Item Name="ble_rsp_gap_end_procedure.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_rsp_gap_end_procedure.vi"/>
			<Item Name="BLED1112-Advertising  packet parser.vi" Type="VI" URL="../BLED1112-Advertising  packet parser.vi"/>
			<Item Name="ble_write_by_handle.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_write_by_handle.vi"/>
			<Item Name="ble_write_by_handle_uint16.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_write_by_handle_uint16.vi"/>
			<Item Name="ble_disconnect_device.vi" Type="VI" URL="../Lib_Bled112 toolkit/ble_functions/ble_disconnect_device.vi"/>
			<Item Name="ble_cmd_connection_disconnect.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_cmd_connection_disconnect.vi"/>
			<Item Name="ble_rsp_connection_disconnect.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_rsp_connection_disconnect.vi"/>
			<Item Name="ble_evt_connection_disconnected.vi" Type="VI" URL="../Lib_Bled112 toolkit/api_commands/ble_evt_connection_disconnected.vi"/>
			<Item Name="BLED1112-Rx Packet parser (EVENT-Attribute Client).vi" Type="VI" URL="../BLED1112-Rx Packet parser (EVENT-Attribute Client).vi"/>
			<Item Name="SUB-BLE Rx data save.vi" Type="VI" URL="../SUB-BLE Rx data save.vi"/>
			<Item Name="BLED1112-Rx Packet parser (EVENT-Connection status).vi" Type="VI" URL="../BLED1112-Rx Packet parser (EVENT-Connection status).vi"/>
			<Item Name="컨트롤-BLED Rx (EVENT-Connection status).ctl" Type="VI" URL="../컨트롤-BLED Rx (EVENT-Connection status).ctl"/>
			<Item Name="BLED1112-Rx Packet parser (RESPONSE-GAP).vi" Type="VI" URL="../BLED1112-Rx Packet parser (RESPONSE-GAP).vi"/>
			<Item Name="컨트롤-BLED Rx (RESPONSE-GAP).ctl" Type="VI" URL="../컨트롤-BLED Rx (RESPONSE-GAP).ctl"/>
			<Item Name="BLED1112-Rx Packet parser (Get Rssi).vi" Type="VI" URL="../BLED1112-Rx Packet parser (Get Rssi).vi"/>
			<Item Name="컨트롤-BLED Rx (Get RSSI).ctl" Type="VI" URL="../컨트롤-BLED Rx (Get RSSI).ctl"/>
			<Item Name="BLED1112-Rx Packet parser (EVENT-Disconnected).vi" Type="VI" URL="../BLED1112-Rx Packet parser (EVENT-Disconnected).vi"/>
			<Item Name="컨트롤-BLED Rx (EVENT-Disconnected).ctl" Type="VI" URL="../컨트롤-BLED Rx (EVENT-Disconnected).ctl"/>
			<Item Name="SUB-BLE Rx data (Mon)-ROM.vi" Type="VI" URL="../SUB-BLE Rx data (Mon)-ROM.vi"/>
			<Item Name="SUB-BLE Rx data (Mon)-CDC IMU.vi" Type="VI" URL="../SUB-BLE Rx data (Mon)-CDC IMU.vi"/>
			<Item Name="SUB-BLE Rx data (Mon)-Classify.vi" Type="VI" URL="../SUB-BLE Rx data (Mon)-Classify.vi"/>
			<Item Name="SUB-BLE Rx data (Mon)-Wait.vi" Type="VI" URL="../SUB-BLE Rx data (Mon)-Wait.vi"/>
			<Item Name="SUB-BLE Rx data (Set)-Classify.vi" Type="VI" URL="../SUB-BLE Rx data (Set)-Classify.vi"/>
			<Item Name="SUB-BLE Rx data Clear.vi" Type="VI" URL="../SUB-BLE Rx data Clear.vi"/>
			<Item Name="_시리얼 포트-수신버퍼 클리어.vi" Type="VI" URL="../_시리얼 포트-수신버퍼 클리어.vi"/>
			<Item Name="SUB-ROM Data convert to table.vi" Type="VI" URL="../SUB-ROM Data convert to table.vi"/>
			<Item Name="컨트롤-BLED Rx (EVENT-Attribute Client).ctl" Type="VI" URL="../컨트롤-BLED Rx (EVENT-Attribute Client).ctl"/>
			<Item Name="SUB-BLE Rx data (Debug)-CDC.vi" Type="VI" URL="../SUB-BLE Rx data (Debug)-CDC.vi"/>
			<Item Name="SUB-Graph plot select.vi" Type="VI" URL="../SUB-Graph plot select.vi"/>
			<Item Name="SUB-Data conv_INT to Float.vi" Type="VI" URL="../SUB-Data conv_INT to Float.vi"/>
			<Item Name="SUB-Exit.vi" Type="VI" URL="../SUB-Exit.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="실행파일" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{D007C9F1-4BF7-4793-B9C3-74DAA68938D7}</Property>
				<Property Name="App_INI_GUID" Type="Str">{68894C12-E6CA-4E75-8F7F-EB33CC9C7994}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{C4536A0D-A889-479E-BF1A-D64BD46CE670}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">실행파일</Property>
				<Property Name="Bld_compilerOptLevel" Type="Int">0</Property>
				<Property Name="Bld_defaultLanguage" Type="Str">Korean</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C/Users/im tech/Desktop/GUI_GEN4 PP3/EXE</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{15D4843B-1839-4C5B-988B-7D3AEE2952F3}</Property>
				<Property Name="Bld_version.build" Type="Int">66</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">GEN4 PP3.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Users/im tech/Desktop/GUI_GEN4 PP3/EXE/GEN4 PP3.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/Users/im tech/Desktop/GUI_GEN4 PP3/EXE/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[2].destName" Type="Str">Template</Property>
				<Property Name="Destination[2].path" Type="Path">/C/Users/im tech/Desktop/GUI_GEN4 PP3/EXE/Template</Property>
				<Property Name="Destination[2].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">3</Property>
				<Property Name="Exe_iconItemID" Type="Ref">/My Computer/ICON2.ico</Property>
				<Property Name="Source[0].itemID" Type="Str">{388A87B8-A2CA-4CD7-A051-583AFCC7697F}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/MAIN.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">2</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/GEN4 FTS Test Report rev1.xlsx</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">Include</Property>
				<Property Name="SourceCount" Type="Int">3</Property>
				<Property Name="TgtF_fileDescription" Type="Str">실행파일</Property>
				<Property Name="TgtF_internalName" Type="Str">실행파일</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright ?2012 </Property>
				<Property Name="TgtF_productName" Type="Str">실행파일</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{F82AC40B-5393-465A-AF73-36D5CF33A4CA}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">GEN4 PP3.exe</Property>
			</Item>
			<Item Name="설치파일" Type="Installer">
				<Property Name="Destination[0].name" Type="Str">GEN4 PP3</Property>
				<Property Name="Destination[0].parent" Type="Str">{3912416A-D2E5-411B-AFEE-B63654D690C0}</Property>
				<Property Name="Destination[0].tag" Type="Str">{AEA9A1FD-CEFD-487C-B9D6-29A5A18D8A8C}</Property>
				<Property Name="Destination[0].type" Type="Str">userFolder</Property>
				<Property Name="DestinationCount" Type="Int">1</Property>
				<Property Name="DistPart[0].flavorID" Type="Str">_deployment_</Property>
				<Property Name="DistPart[0].productID" Type="Str">{36AADB39-88B7-4228-8421-F4EBD0B8D826}</Property>
				<Property Name="DistPart[0].productName" Type="Str">NI-VISA 런타임 15.5</Property>
				<Property Name="DistPart[0].upgradeCode" Type="Str">{8627993A-3F66-483C-A562-0D3BA3F267B1}</Property>
				<Property Name="DistPart[1].flavorID" Type="Str">DefaultFull</Property>
				<Property Name="DistPart[1].productID" Type="Str">{C8D01F7E-129E-4C0A-A623-DBF2DB298EF8}</Property>
				<Property Name="DistPart[1].productName" Type="Str">NI LabVIEW 런타임 2015 SP1 f3</Property>
				<Property Name="DistPart[1].SoftDep[0].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[0].productName" Type="Str">NI LabVIEW 런타임 2015 SP1 영어 외 다른 언어 지원.</Property>
				<Property Name="DistPart[1].SoftDep[0].upgradeCode" Type="Str">{128ABF1E-5F69-40D1-8A81-33DCF8229F08}</Property>
				<Property Name="DistPart[1].SoftDep[1].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[1].productName" Type="Str">NI ActiveX 컨테이너</Property>
				<Property Name="DistPart[1].SoftDep[1].upgradeCode" Type="Str">{1038A887-23E1-4289-B0BD-0C4B83C6BA21}</Property>
				<Property Name="DistPart[1].SoftDep[10].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[10].productName" Type="Str">NI mDNS Responder 14.0</Property>
				<Property Name="DistPart[1].SoftDep[10].upgradeCode" Type="Str">{9607874B-4BB3-42CB-B450-A2F5EF60BA3B}</Property>
				<Property Name="DistPart[1].SoftDep[11].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[11].productName" Type="Str">NI 배포 프레임워크 2015</Property>
				<Property Name="DistPart[1].SoftDep[11].upgradeCode" Type="Str">{838942E4-B73C-492E-81A3-AA1E291FD0DC}</Property>
				<Property Name="DistPart[1].SoftDep[12].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[12].productName" Type="Str">NI 에러 리포트 2015</Property>
				<Property Name="DistPart[1].SoftDep[12].upgradeCode" Type="Str">{42E818C6-2B08-4DE7-BD91-B0FD704C119A}</Property>
				<Property Name="DistPart[1].SoftDep[2].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[2].productName" Type="Str">NI System Web Server 15.5</Property>
				<Property Name="DistPart[1].SoftDep[2].upgradeCode" Type="Str">{FCF64B73-B7D4-4971-8F11-24BAF7CC3E6C}</Property>
				<Property Name="DistPart[1].SoftDep[3].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[3].productName" Type="Str">Math Kernel 라이브러리</Property>
				<Property Name="DistPart[1].SoftDep[3].upgradeCode" Type="Str">{4C0854AD-9BFC-4494-A4E0-D96C0C07F1F2}</Property>
				<Property Name="DistPart[1].SoftDep[4].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[4].productName" Type="Str">NI Logos 5.7</Property>
				<Property Name="DistPart[1].SoftDep[4].upgradeCode" Type="Str">{5E4A4CE3-4D06-11D4-8B22-006008C16337}</Property>
				<Property Name="DistPart[1].SoftDep[5].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[5].productName" Type="Str">NI TDM Streaming 15.2</Property>
				<Property Name="DistPart[1].SoftDep[5].upgradeCode" Type="Str">{4CD11BE6-6BB7-4082-8A27-C13771BC309B}</Property>
				<Property Name="DistPart[1].SoftDep[6].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[6].productName" Type="Str">NI LabVIEW 웹 서버 2015</Property>
				<Property Name="DistPart[1].SoftDep[6].upgradeCode" Type="Str">{78AAB900-C712-11E3-9C1A-0800200C9A66}</Property>
				<Property Name="DistPart[1].SoftDep[7].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[7].productName" Type="Str">NI LabVIEW Real-Time NBFifo 2015</Property>
				<Property Name="DistPart[1].SoftDep[7].upgradeCode" Type="Str">{25643B9A-90E8-4100-B30C-10EC4DE2EE68}</Property>
				<Property Name="DistPart[1].SoftDep[8].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[8].productName" Type="Str">NI VC2008MSMs</Property>
				<Property Name="DistPart[1].SoftDep[8].upgradeCode" Type="Str">{FDA3F8BB-BAA9-45D7-8DC7-22E1F5C76315}</Property>
				<Property Name="DistPart[1].SoftDep[9].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[1].SoftDep[9].productName" Type="Str">NI VC2010MSMs</Property>
				<Property Name="DistPart[1].SoftDep[9].upgradeCode" Type="Str">{EFBA6F9E-F934-4BD7-AC51-60CCA480489C}</Property>
				<Property Name="DistPart[1].SoftDepCount" Type="Int">13</Property>
				<Property Name="DistPart[1].upgradeCode" Type="Str">{CA8FF739-2EDA-4134-9A70-0F5DD933FDED}</Property>
				<Property Name="DistPartCount" Type="Int">2</Property>
				<Property Name="INST_autoIncrement" Type="Bool">true</Property>
				<Property Name="INST_buildLocation" Type="Path">/C/Users/im tech/Desktop/GUI_GEN4 PP3/Install files</Property>
				<Property Name="INST_buildSpecName" Type="Str">설치파일</Property>
				<Property Name="INST_defaultDir" Type="Str">{AEA9A1FD-CEFD-487C-B9D6-29A5A18D8A8C}</Property>
				<Property Name="INST_productName" Type="Str">GEN4 PP3</Property>
				<Property Name="INST_productVersion" Type="Str">1.0.11</Property>
				<Property Name="InstSpecBitness" Type="Str">32-bit</Property>
				<Property Name="InstSpecVersion" Type="Str">15018010</Property>
				<Property Name="MSI_autoselectDrivers" Type="Bool">true</Property>
				<Property Name="MSI_distID" Type="Str">{A3DF35F6-5CB1-425E-ACF3-4EC4AA9B233D}</Property>
				<Property Name="MSI_osCheck" Type="Int">0</Property>
				<Property Name="MSI_upgradeCode" Type="Str">{344942AF-B019-4883-829E-B7FA9801C43C}</Property>
				<Property Name="RegDest[0].dirName" Type="Str">Software</Property>
				<Property Name="RegDest[0].dirTag" Type="Str">{DDFAFC8B-E728-4AC8-96DE-B920EBB97A86}</Property>
				<Property Name="RegDest[0].parentTag" Type="Str">2</Property>
				<Property Name="RegDestCount" Type="Int">1</Property>
				<Property Name="Source[0].dest" Type="Str">{AEA9A1FD-CEFD-487C-B9D6-29A5A18D8A8C}</Property>
				<Property Name="Source[0].File[0].dest" Type="Str">{AEA9A1FD-CEFD-487C-B9D6-29A5A18D8A8C}</Property>
				<Property Name="Source[0].File[0].name" Type="Str">GEN4 PP3.exe</Property>
				<Property Name="Source[0].File[0].Shortcut[0].destIndex" Type="Int">1</Property>
				<Property Name="Source[0].File[0].Shortcut[0].name" Type="Str">GEN4 PP3</Property>
				<Property Name="Source[0].File[0].Shortcut[0].subDir" Type="Str"></Property>
				<Property Name="Source[0].File[0].Shortcut[1].destIndex" Type="Int">0</Property>
				<Property Name="Source[0].File[0].Shortcut[1].name" Type="Str">GEN4 PP3</Property>
				<Property Name="Source[0].File[0].Shortcut[1].subDir" Type="Str">GEN4 PP3</Property>
				<Property Name="Source[0].File[0].ShortcutCount" Type="Int">2</Property>
				<Property Name="Source[0].File[0].tag" Type="Str">{F82AC40B-5393-465A-AF73-36D5CF33A4CA}</Property>
				<Property Name="Source[0].FileCount" Type="Int">1</Property>
				<Property Name="Source[0].name" Type="Str">실행파일</Property>
				<Property Name="Source[0].tag" Type="Ref">/My Computer/Build Specifications/실행파일</Property>
				<Property Name="Source[0].type" Type="Str">EXE</Property>
				<Property Name="SourceCount" Type="Int">1</Property>
			</Item>
		</Item>
	</Item>
</Project>
