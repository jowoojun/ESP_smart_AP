import React, {PureComponent} from 'react';


export default class NetworkInfoSide extends PureComponent{

    render(){

        return(
            <div className="col-md-4">
                <div className="well tabcontent current" id="internet_info_desc">
                    <h4>설명</h4>
                        <ul>
                            <li>IP주소 : 컴퓨터 네트워크에서 장치들이 서로를 인식하고 통신을 하기 위해서 사용하는 특수한 번호이다.
                                네트워크에 연결된 장치가 라우터이든 일반 서버이든, 모든 기계는 이 특수한 번호를 가지고 있어야 한다.
                                이 번호를 이용하여 발신자를 대신하여 메시지가 전송되고 수신자를 향하여 예정된 목적지로 전달된다.
                                IP 주소를 줄여서 IP라고 부르기도 하나 IP는 인터넷 규약 자체를 가리키는 말이기 때문에 엄밀하게는 구별해야 한다.</li>
                        </ul>
                </div>
            </div>
        );
    }
}
