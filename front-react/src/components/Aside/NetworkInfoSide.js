import React, {PureComponent} from 'react';


class NetworkInfoSide extends PureComponent{

    render(){

        return(
            <div className="col-md-4">
                <div className="well tabcontent current" id="internet_info_desc">
                    <h4>설명</h4>
                      <ul>
                        <li>SSID : 무선 랜을 통해 전송되는 패킷들의 각 헤더에 덧붙여지는 32byte 길이의 고유 식별자</li>
                        <li>외부 IP : </li>
                        <li>기본 DNS 서버 :</li>
                        <li>보조 DNS 서버 :</li>
                        <li>GATEWAY : </li>
                        <li>DHCP 시작 IP :</li>
                        <li>DHCP 종료 IP :</li>
                        <li>MAC 주소 :</li>
                        <li>원격관리 :</li>
                      </ul>
                </div>
            </div>
        );
    }
}

export default NetworkInfoSide;
