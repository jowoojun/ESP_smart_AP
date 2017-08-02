import React, {PureComponent} from 'react';

class InternetConnectSide extends PureComponent{

    render(){

        return(
            <div className="col-md-4">
                <div className="well tabcontent current" id="dynamic_ip_desc">
                    <h4>설명</h4>
                      <ul>
                        <li>유동IP 설명</li>
                      </ul>
                </div>
                <div className="well tabcontent" id="static_ip_desc">
                    <h4>설명</h4>
                      <ul>
                        <li>고정IP 설명</li>
                      </ul>
                </div>
            </div>
        );
    }
}

export default InternetConnectSide;
