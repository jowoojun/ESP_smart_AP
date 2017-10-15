import React, {PureComponent} from 'react';

export default class ReservationAside extends PureComponent{

    render(){

        return(
            <div className="col-md-4">
                <div className="well tabcontent " id="dynamic_ip_desc">
                    <h4>설명</h4>
                    <ul>
                        <li>예약 차단 : </li>
                    </ul>
                </div>
            </div>
        );
    }
}
