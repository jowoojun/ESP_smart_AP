import React, {PureComponent} from 'react';

export default class SystemLog extends PureComponent{

    render(){

        return(
            <div className="col-md-8 well tabcontent" id="system_log">
                <h1 className="page-header">
                    <small>System Log</small>
                </h1>
                <div className="table-responsive">
                    <fieldset className="log_field">
                        <select size="2" id="log_list">

                        {this.props.logs.map((item, index) => {
                            return(
                                <option draggable="true" key={index}>내용 : {item.log_content} 시간 : {item.log_time}</option>
                            )
                        })}
                        </select>
                    </fieldset>
                </div>
            </div>
        );
    }
}
