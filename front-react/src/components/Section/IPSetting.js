import React, {PureComponent} from 'react';

export default class IPSetting extends PureComponent{

    render(){
        return(
            <div className="col-md-8 well tabcontent" id="dynamic_ip">
                <h1 className="page-header">
                    <small>내부 네트워크 설정</small>
                </h1>
                <div className="table-responsive">
                    <table className="table table-bordered">
                        <tr>
                            <th>IP 주소</th>
                            <td>
                                <input className="ip_field" name="ip_inet1" type="text" value="" maxLength="3" required/>.
                                <input className="ip_field" name="ip_inet2" type="text" value="" maxLength="3" required/>.
                                <input className="ip_field" name="ip_inet3" type="text" value="" maxLength="3" required/>.
                                <input className="ip_field" name="ip_inet4" type="text" value="" maxLength="3" required/>
                            </td>
                        </tr>
                        <tr>
                            <th>서브넷마스크</th>
                            <td>
                                <input className="ip_field" name="subnet_inet1" type="text" value="" maxLength="3" required/>.
                                <input className="ip_field" name="subnet_inet2" type="text" value="" maxLength="3" required/>.
                                <input className="ip_field" name="subnet_inet3" type="text" value="" maxLength="3" required/>.
                                <input className="ip_field" name="subnet_inet4" type="text" value="" maxLength="3" required/>
                            </td>
                        </tr>
                        <tr>
                            <th>DHCP 주소</th>
                            <td>
                                <input className="ip_field dhcp_range" name="start_dhcp1" type="text" value="" maxLength="3" required />.
                                <input className="ip_field dhcp_range" name="start_dhcp2" type="text" value="" maxLength="3" required />.
                                <input className="ip_field dhcp_range" name="start_dhcp3" type="text" value="" maxLength="3" required />.
                                <input className="ip_field dhcp_range" name="start_dhcp4" type="text" value="" maxLength="3" required /> ~
                                <input className="ip_field dhcp_range" name="end_dhcp1" type="text" value="" maxLength="3" required />.
                                <input className="ip_field dhcp_range" name="end_dhcp2" type="text" value="" maxLength="3" required />.
                                <input className="ip_field dhcp_range" name="end_dhcp3" type="text" value="" maxLength="3" required />.
                                <input className="ip_field dhcp_range" name="end_dhcp4" type="text" value="" maxLength="3" required />
                            </td>
                        </tr>
                    </table>
                    <div className="col-md-12">
                        <input type="submit" className="btn btn-default save_config" value="적용" />
                    </div>
                </div>
            </div>
        );
    }
}
