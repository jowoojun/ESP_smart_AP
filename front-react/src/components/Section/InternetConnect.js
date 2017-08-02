import React, {PureComponent} from 'react';


class InternetConnect extends PureComponent{

    render(){

        return(
            
            <div className="col-md-8 well tabcontent" id="dynamic_ip">
                <h1 className="page-header">
                    <small>인터넷 연결설정</small>
                </h1>
                <div className="table-responsive">
                  <table className="table table-bordered">
                    <tr>
                      <th>연결방식</th>
                      <td>
                        <input type="radio" name="con_type" value="ip_dynamic" checked/>유동IP
                        <input type="radio" name="con_type" value="ip_static"/>고정IP
                      </td>
                    </tr>
                  </table>

                  <table className="table table-bordered" id="ip_dynamic_cont">
                    <tr>
                      <th>DNS 서버설정</th>
                      <td>
                        <input type="radio" name="dns_server" value="dns_dynamic" checked/>자동
                        <input type="radio" name="dns_server" value="dns_static"/>수동
                      </td>
                    </tr>
                    <tr>
                      <th>기본 DNS</th>
                      <td>
                        <input className="ip_field dns_default" name="dns_d1" type="text" value="" maxlength="3" required readonly/>.
                        <input className="ip_field dns_default" name="dns_d2" type="text" value="" maxlength="3" required readonly/>.
                        <input className="ip_field dns_default" name="dns_d3" type="text" value="" maxlength="3" required readonly/>.
                        <input className="ip_field dns_default" name="dns_d4" type="text" value="" maxlength="3" required readonly/>
                      </td>
                    </tr>
                    <tr>
                      <th>보조 DNS
                      </th>
                      <td>
                        <input className="ip_field dns_secondary" name="dns_s1" type="text" value="" maxlength="3" required readonly/>.
                        <input className="ip_field dns_secondary" name="dns_s2" type="text" value="" maxlength="3" required readonly/>.
                        <input className="ip_field dns_secondary" name="dns_s3" type="text" value="" maxlength="3" required readonly/>.
                        <input className="ip_field dns_secondary" name="dns_s4" type="text" value="" maxlength="3" required readonly/>
                      </td>
                    </tr>
                    <tr>
                      <th>
                        채널 설정
                      </th>
                      <td>
                        <select>
                          <option value="1">채널1</option>
                          <option value="2">채널2</option>
                        </select>
                      </td>
                    </tr>
                </table>

                <table className="table table-bordered" id="ip_static_cont">
                  <tr>
                    <th>외부 IP</th>
                    <td>
                      <input className="ip_field" name="ip_o1" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="ip_o2" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="ip_o3" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="ip_o4" type="text" value="" maxlength="3" required/>
                    </td>
                  </tr>
                  <tr>
                    <th>서브넷마스크</th>
                    <td>
                      <input className="ip_field" name="subnet1" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="subnet2" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="subnet3" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="subnet4" type="text" value="" maxlength="3" required/>
                    </td>
                  </tr>
                  <tr>
                    <th>게이트웨이</th>
                    <td>
                      <input className="ip_field" name="gateway1" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="gateway2" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="gateway3" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="gateway4" type="text" value="" maxlength="3" required/>
                    </td>
                  </tr>
                  <tr>
                    <th>기본 DNS</th>
                    <td>
                      <input className="ip_field" name="static_dns_d1" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="static_dns_d2" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="static_dns_d3" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="static_dns_d4" type="text" value="" maxlength="3" required/>
                    </td>
                  </tr>
                  <tr>
                    <th>보조 DNS
                    </th>
                    <td>
                      <input className="ip_field" name="static_dns_s1" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="static_dns_s2" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="static_dns_s3" type="text" value="" maxlength="3" required/>.
                      <input className="ip_field" name="static_dns_s4" type="text" value="" maxlength="3" required/>
                    </td>
                  </tr>
                  <tr>
                    <th>
                      채널 설정
                    </th>
                    <td>
                      <select>
                        <option value="1">채널1</option>
                        <option value="2">채널2</option>
                      </select>
                    </td>
                  </tr>
              </table>
            </div>

              <h1 className="page-header">
                    <small>내부 네트워크 설정</small>
              </h1>
                <div className="table-responsive">
                  <table className="table table-bordered">
                    <tr>
                      <th>
                        IP 주소
                      </th>
                      <td>
                        <input className="ip_field" name="ip_inet1" type="text" value="" maxlength="3" required/>.
                        <input className="ip_field" name="ip_inet2" type="text" value="" maxlength="3" required/>.
                        <input className="ip_field" name="ip_inet3" type="text" value="" maxlength="3" required/>.
                        <input className="ip_field" name="ip_inet4" type="text" value="" maxlength="3" required/>
                      </td>
                    </tr>
                    <tr>
                      <th>
                        서브넷마스크
                      </th>
                      <td>
                        <input className="ip_field" name="subnet_inet1" type="text" value="" maxlength="3" required/>.
                        <input className="ip_field" name="subnet_inet2" type="text" value="" maxlength="3" required/>.
                        <input className="ip_field" name="subnet_inet3" type="text" value="" maxlength="3" required/>.
                        <input className="ip_field" name="subnet_inet4" type="text" value="" maxlength="3" required/>
                      </td>
                    </tr>
                    <tr>
                      <th>
                        DHCP 사용
                      </th>
                      <td>
                        <input type="radio" name="dhcp" value="use" checked/>사용
                        <input type="radio" name="dhcp" value="stop"/>중지
                      </td>
                    </tr>
                    <tr>
                      <th>
                        DHCP 주소
                      </th>
                      <td>
                        <input className="ip_field dhcp_range" name="start_dhcp1" type="text" value="" maxlength="3" required />.
                        <input className="ip_field dhcp_range" name="start_dhcp2" type="text" value="" maxlength="3" required />.
                        <input className="ip_field dhcp_range" name="start_dhcp3" type="text" value="" maxlength="3" required />.
                        <input className="ip_field dhcp_range" name="start_dhcp4" type="text" value="" maxlength="3" required /> ~
                        <input className="ip_field dhcp_range" name="end_dhcp1" type="text" value="" maxlength="3" required />.
                        <input className="ip_field dhcp_range" name="end_dhcp2" type="text" value="" maxlength="3" required />.
                        <input className="ip_field dhcp_range" name="end_dhcp3" type="text" value="" maxlength="3" required />.
                        <input className="ip_field dhcp_range" name="end_dhcp4" type="text" value="" maxlength="3" required />
                      </td>
                    </tr>
                  </table>
                </div>
            </div>
        );
    }
}

export default InternetConnect;
