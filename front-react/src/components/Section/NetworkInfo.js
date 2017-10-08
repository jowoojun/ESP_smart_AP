import React, {PureComponent} from 'react';

export default class NetworkInfo extends PureComponent{

    render(){

        return(
            <div id="internet_info" className="col-md-8 well tabcontent current">
                <h1 className="page-header">
                    <small>인터넷 정보</small>
                </h1>
                <div className="table-responsive">
                    <table className="table table-bordered">
                        <tr>
                            <th>인터넷 연결상태</th>
                            <td>인터넷에 정상적으로 연결됨</td>
                        </tr>
                        <tr>
                            <th>외부 IP</th>
                            <td></td>
                        </tr>
                        <tr>
                            <th>기본 DNS 서버</th>
                            <td></td>
                        </tr>
                        <tr>
                            <th>보조 DNS 서버</th>
                            <td></td>
                        </tr>
                        <tr>
                            <th>GATEWAY</th>
                            <td></td>
                        </tr>
                        <tr>
                            <th>DHCP 시작 IP</th>
                          <td></td>
                        </tr>
                        <tr>
                            <th>DHCP 종료 IP</th>
                            <td></td>
                        </tr>
                        <tr>
                            <th>MAC 주소</th>
                            <td></td>
                        </tr>
                    </table>
                </div>
            </div>
        );
    }
}
