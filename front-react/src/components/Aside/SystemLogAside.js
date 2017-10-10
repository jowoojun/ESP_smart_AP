import React, {PureComponent} from 'react';

export default class SystemLogAside extends PureComponent{

    render(){
        return(
            <div className="col-md-4">
                <div className="well tabcontent " id="dynamic_ip_desc">
                    <h4>설명</h4>
                    <ul>
                        <li>시스템 로그 설명</li>
                    </ul>
                </div>
            </div>
        );
    }
}
